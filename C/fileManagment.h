#ifndef _FILEMANAGMENT_H
#define _FILEMANAGMENT_H
#include <stdbool.h>

typedef struct note{
    char title[50];
    char content[255];
} Note;

void readFile(Note arr[100]);
bool writeFile(Note arr[100]);
#endif