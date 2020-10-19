#!/bin/bash

FILE_PATH="Input.csv"
RESULT_FILE="Results.csv"
printf "Name,Email-ID,GIT-URL,Git-Clone-Status,Build-status,Cppcheck,Valgrind" > $RESULT_FILE

while IFS=, read -r NAME ID REPO;
do
   [[$NAME != 'Name']] && echo "$NAME"
   [[$ID != 'Email ID']] && echo "$ID"
   if [ "$REPO" != 'Repo Link' ]; 
       then
       repo=$REPO
       git clone "$REPO"
       if [$? -eq 0]; 
          then
          clone="Clone success"
       else
          clone="Clone Failure"
       fi 
        REPO= `echo "$REPO" | cut -d'/' -c5` 
        echo "REPO = $REPO"
        make -C "$REPO"
       if [$? -eq 0]; 
           then
           er="$ERROR"
       fi
        make test -C $REPO
        EXE=`find "$REPO" -name "Test*.out"`
        valgrind "./$EXE" 2>log.txt
        STR = $( tail -n 1 log.txt)
        val=$(echo ${STR:24:3})
        verr="$val"
        printf "$name,$id,$repo,$clone,$bu,$er,$verr\n" >> $RESULT_FILE
   fi
done < ${FILE_PATH}
