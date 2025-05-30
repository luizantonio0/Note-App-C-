#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct note{
    char* title;
    char* content;
} Note;

Note notes[100];

int lenght(Note vet[]) {
    int result = sizeof(vet)/sizeof(vet[0]);
    return 0;
}

// bool saveNote(Note note){
//     int index = lenght(notes);
//     printf("%d", index);
//     return true;
// }

// void writeNote(){
//     // Note newNote;
//     // printf("Choose the title for your note: ");
//     // fgets(newNote.title, 50, stdin);

//     // printf("Write your note: ");
//     // fgets(newNote.content, 511, stdin);

//     // if (saveNote(newNote)){
//     //     printf("Note saved Successfully!");
//     // } else{
//     //     printf("Some Error has occurred!");
//     // }
// }

int menu(){
    printf("Choose a option: \n 1. Write note\n 2. Show notes\n 3. Update note\n 4. Erase note\n 5. Exit\n");
    
    int option;
    scanf("%d", &option);
    return option;
}


int main(){
    while (true)
    {
        int option = menu();
        if (option == 1){
            printf("%d", lenght(notes));

        } else if (option == 2){
            for (int i = 0; i < 10; i++)
            {
                Note newnote;

                newnote.content = "teste";
                newnote.title = "TESTE";
                
                notes[i] = newnote;
            }
        }else if (option == 5){
            break;
        }
    }

    return 0;
}