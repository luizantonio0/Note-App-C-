// # include "fileManagment.h"
// # include <stdbool.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>

//     bool readFile(Note arr[100])
//     {
//         FILE *data = fopen("data.csv", "r");

//         char line[306];

//         if (data == NULL) {
//             return false;
//         }

//         int index = 0;

//         while ((fgets(line, 306, data) != NULL) && index < 100)
//         {
//             char *ptr = strchr(line, ',');
//             if (ptr == NULL) {
//                 continue; // Linha mal formatada, ignora
//             }

//             int pos = ptr - line;

//             strncpy(arr[index].title, line, pos);
//             arr[index].title[pos] = '\0';

//             strcpy(arr[index].content, ptr + 1);
//             arr[index].content[strcspn(arr[index].content, "\n")] = '\0';
//             index++;
//         }

//         fclose(data);
//         return true;
//     }
//     bool writeFile(Note arr[100]){
//         FILE *data = fopen("data.csv", "w");

//         for (int i = 0; i < 100; i++)
//         {
//             char line[306];

//             memcpy(line, arr[i].title, 50);
//             strcat(line, ",");
//             strcat(line, arr[i].content);
//             strcat(line, "\n");

//             fputs(line, data);    
//         }

//         fclose(data);
//         return true;
//     }