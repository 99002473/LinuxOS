#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];
    char ch;
    int nchar, nword, nline;
    
    file = fopen("file1.txt", "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    nchar = nword = nline = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        nchar++;

        if (ch == '\n' || ch == '\0')                             //checking for a line
            nline++;

        
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') //cheching for a word
            nword++;
    }
    if (nchar > 0)
    {
        nword++;
        nline++;
    }
    printf("\n");
    printf("Total number of char = %d\n", nchar);
    printf("Total number of word      = %d\n", nword);
    printf("Total number of line      = %d\n", nline);

    fclose(file);

    return 0;
} 
