#ifndef _FILEMANAGMENT_H
#define _FILEMANAGMENT_H
#include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct note{
    char title[50];
    char content[255];
} Note;

    bool readFile(Note arr[100])
    {
        FILE *data = fopen("data.csv", "r");

        char line[306];

        if (data == NULL) {
            return false;
        }

        int index = 0;

        while ((fgets(line, 306, data) != NULL) && index < 100)
        {
            char *ptr = strchr(line, ',');
            if (ptr == NULL) {
                continue;
            }

            int pos = ptr - line;

            strncpy(arr[index].title, line, pos);
            // arr[index].title[pos] = '\0';

            strcpy(arr[index].content, ptr + 1);
            // arr[index].content[strcspn(arr[index].content, "\n")] = '\0';
            index++;
        }

        fclose(data);
        return true;
    }
    //TODO: remover '\n' no fim da string
    bool writeFile(Note arr[100], int size){
        FILE *data = fopen("data.csv", "w");

        for (int i = 0; i < size; i++)
        {
            char line[306];

            memcpy(line, arr[i].title, 50);
            strcat(line, ",");
            strcat(line, arr[i].content);
            strcat(line, "\n");

            fputs(line, data);    
        }

        fclose(data);
        return true;
    }
#endif