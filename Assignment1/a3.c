#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];
    char ch;
    int char_num, word_num, line_num;
    
    file = fopen("file1.txt", "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }

    char_num = word_num = line_num = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        char_num++;

        /* Check new line */
        if (ch == '\n' || ch == '\0')
            line_num++;

        /* Check word_num */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            word_num++;
    }
    if (char_num > 0)
    {
        word_num++;
        line_num++;
    }
    printf("\n");
    printf("Total char_num = %d\n", char_num);
    printf("Total word_num      = %d\n", word_num);
    printf("Total line_num      = %d\n", line_num);

    fclose(file);

    return 0;
} 
