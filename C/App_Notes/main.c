#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

typedef struct note{
    char title[50];
    char content[255];
} Note;

Note notes[100];
int size = 0;


bool saveNote(Note note){
    if (size >= 100) {
        printf("Note limit reached. Cannot save more notes.\n");
        return false;
    }
    notes[size] = note;
    size++;
    return true;
}

void writeNote(){
    Note newNote;
    printf("Choose the title for your note: ");
    fgets(newNote.title, 50, stdin);
    printf("\nWrite your note: ");
    fgets(newNote.content, 255, stdin);

    if (saveNote(newNote)){
        printf("Note saved Successfully!");
    } else{
        printf("Some Error has occurred!");
    }
}

void showNotes(){
    if (size == 0) {
        printf("No notes available.\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("----------------------------------------------------------------\n");
        printf("Note %d:\n", i + 1);
        printf("Title: %s\n", notes[i].title);
        printf("Content: %s\n", notes[i].content);
        printf("----------------------------------------------------------------\n");
    }
}

int menu(){
    printf("Choose a ççoption: \n 1. Write note\n 2. Show notes\n 3. Update note\n 4. Erase note\n 5. Exit\n");
    
    int option;
    scanf("%d", &option);
    fflush(stdin);
    return option;
}


int main(){
    while (true)
    {
        int option = menu();
        switch (option)
        {
        case 1: 
            writeNote();
            break;
        case 2:
            showNotes();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Exiting the application.\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}