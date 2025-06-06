#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "fileManagment.h"

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

    size_t len = strlen(newNote.title);
    if (len > 0 && newNote.title[len - 1] == '\n') {
        newNote.title[len - 1] = '\0';
    }

    printf("\nWrite your note: ");
    fgets(newNote.content, 255, stdin);

    len = strlen(newNote.content);
    if (len > 0 && newNote.content[len - 1] == '\n') {
        newNote.content[len - 1] = '\0';
    }

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
        printf("\n----------------------------------------------------------------");
}

void saveInMemory(Note arr[100]){
    if (writeFile(arr, size)){
        printf("Saved succesfully\n");
        return;
    }

    printf("A error has occured\n");
}

int menu(){
    printf("\nChoose a option: \n1. Write note\n2. Show notes\n3. Update note\n4. Erase note\n5. Exit\n6. Save notes\n7. Reload notes\n");
    
    int option;
    scanf("%d", &option);
    fflush(stdin);
    return option;
}

int lenght(Note arr[]) {
    int count = 0;
    while (count < 100 && strlen(arr[count].title) > 0) {
        count++;
    }
    return count;
}

void readInMemory(){
    readFile(notes);
    size = lenght(notes);
}


int main(){

    readInMemory();

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
        {
            system("cls");

            char titleUpdate[50];
            printf("What is the title of the note you wanna update? ");
            fgets(titleUpdate, 50, stdin);


            if (!update(binarySearch(titleUpdate))) printf("Note not found!");
            break;
        }
        case 4:
        {
            system("cls");
            
            char titleRemove[50];
            printf("What is the title of the note you wanna remove? ");
            fgets(titleRemove, 50, stdin);

            if (!erase(binarySearch(titleRemove))) printf("Note not found!");
            system("cls");
            break;
        }
        case 5:
        {
            system("cls");

            char charOption;
            printf("Do you wanna save the changes? (s/n) ");
            scanf(" %c", &charOption);
            switch (charOption)
            {
            case 's':
            case 'S':
                saveInMemory(notes);
                break;
            case 'n':
            case 'N':
                printf("Exiting the application.\n");
                return 0;
            default:
                printf("Invalid option.");
                break;
            }
            break;
        }
        case 6:
            system("cls");
            saveInMemory(notes);
            break;
        case 7:
            system("cls");
            printf("reloading your notes...");
            readFile(notes);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
    return 0;
}