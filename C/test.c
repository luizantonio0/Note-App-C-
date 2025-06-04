#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[] = "exemplo,teste";
    char *ptr = strchr(texto, ',');
    if (ptr != NULL) {
    int pos = ptr - texto; // posição do caractere ','
    printf("Posição: %d\n", pos);
    }


return 0;
}