#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

 struct Pessoa
    {
        int idade;
        char nome[50];
    };

int main(){

    struct Pessoa pessoa1;
    
    strcpy(pessoa1.nome, "ERROO");

    struct Pessoa escola[50];
    
    printf("insira o nome: ");

    fgets(escola[1].nome, sizeof(escola[1].nome), stdin);
    escola[0] = pessoa1;

    struct Pessoa *p;

    p = &escola[0];

    *p->nome = "LUIZ";

    printf("%s", escola[0].nome);
    printf("\n%s", pessoa1.nome);
    printf("s", *p);

    return 0;
}