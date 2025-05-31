#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct note{
    char title[50];
    char content[255];
} Note;

Note notes[100];
int size = 0;

int binarySearch(char title[50]){
    int l = 0;
    int r = size;
    int mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        int cmp = strcmp(notes[mid].title, title);
        if (cmp == 0){
            return mid;
        }
        if (cmp < 0){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    return -1;
}

void bubbleSort(Note vet[]){
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-1-i; j++)
        {
            if (strcmp (vet[j].title, vet[j+1].title) > 0)
            {
                Note aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

bool erase(int index){
   if (index < 0) return false; 
    for (int i = index; i < size - 1; i++) {
        notes[i] = notes[i + 1];
    }
    size--;
    return true;
}

bool saveNote(Note note){
    if (size >= 100) {
        printf("Note limit reached. Cannot save more notes.\n");
        return false;
    }
    notes[size] = note;
    size++;
    bubbleSort(notes);
    return true;
}

bool update(int index){
    if (index < 0) return false;

    printf("\nWrite your note: ");
    fgets(notes[index].content, 255, stdin);
    
    system("cls");
    return true;
}

Note writeNote(){
    Note newNote;
    printf("Choose the title for your note: ");
    fgets(newNote.title, 50, stdin);
    printf("\nWrite your note: ");
    fgets(newNote.content, 255, stdin);
    system("cls");

    return newNote;
}

void showNotes(){
    if (size == 0) {
        printf("No notes available.");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("----------------------------------------------------------------\n");
        printf("Note %d:\n", i + 1);
        printf("Title: %s\n", notes[i].title);
        printf("Content: %s", notes[i].content);
    }
        printf("----------------------------------------------------------------");
}

int menu(){
    printf("\nChoose a option: \n 1. Write note\n 2. Show notes\n 3. Update note\n 4. Erase note\n 5. Exit\n");
    
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
            system("cls");
            if (saveNote(writeNote())){
                printf("Note saved successfully!\n");
            }
            break;
        case 2:
            system("cls");
            showNotes();
            getchar();
            system("cls");
            break;
        case 3:
            system("cls");

            char title[50];
            printf("What is the title of the note you wanna update? ");
            fgets(title, 50, stdin);


            if (!update(binarySearch(title))) printf("Note not found!");
            break;
        case 4:
            system("cls");

            printf("What is the title of the note you wanna remove? ");
            fgets(title, 50, stdin);

            if (!erase(binarySearch(title))) printf("Note not found!");
            system("cls");
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