# include "fileManagment.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

    void readFile(Note arr[100])
    {
        FILE *data = fopen("data.csv", "r");

        char title[50];
        char content[255];
        char c;
        char *line;
        
        if (data == NULL){
            data = fopen("data.csv", "w+");
        }

        int index = 0;
        
        //Ler uma linha inteira de uma vez
        while ((c = fgetc(data) != EOF))
        {
            line += c;
            if (c == '\n')
            {

                for (int i = 0; i < 50; i++)
                {
                    title[i] = line[i];
                }

                for (int i = 50; i < 305; i++)
                {
                    content[i] = line[i];
                }
                
                strcpy(arr[index].title, title);
                strcpy(arr[index].content, content);
                index++;
            }

        }

        fclose(data);
        data = NULL;
    }
    bool writeFile(Note arr[100]){
        return true;
    }
    int main(){
    

        Note notes[100];
        readFile(notes);
        printf("a\n");
        printf(notes[0].title);

    // char c;
    // char *input;
    // FILE *fl = fopen("test.txt", "r+");

    // if(fl == NULL)
    // {
    //     exit(1);
    // }

    // while ((c = fgetc(fl)) != EOF)
    // {
    //     printf("%c", c);
    // }

    // printf("\nWrite your msg: ");
    // scanf("%s", input);
    // fputs(input, fl);
    

    // fclose(fl);
    // fl = NULL;
    
    return 0;
}