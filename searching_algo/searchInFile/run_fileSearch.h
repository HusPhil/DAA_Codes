#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "helper_functions.h"

void runSearchInFile() {
    int choice;

    do
    {
        system("cls");
        char filePath[10000];
        printf("Enter filePath: ");
        scanf("%s", filePath);

        

        char *fileContent = extractTextFromFile(filePath);
        if(fileContent==NULL) return;

        
        printf("Select an option:\n1==Search Word\n2==Find and Replace\n3==View file content\n0==Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char wordToSearch[10000];
        char wordForReplace[10000];
        char replaceAll = 'n';

        switch(choice) {
            case 1:
                printf("Enter the word: ");
                scanf("%s", wordToSearch);
                searchWord(fileContent, wordToSearch);
                break;
            case 2:
                printf("Enter the target word: ");
                scanf("%s", wordToSearch);
                printf("Enter the replacement word: ");
                scanf("%s", wordForReplace);

                printf("Replace all instances? [y/n] ");
                scanf(" %c", &replaceAll);


                if(replaceAll == 'y' || replaceAll == 'Y')
                {

                    findAndReplace(fileContent, wordToSearch, wordForReplace, filePath, 1);
                }
                else
                {

                    findAndReplace(fileContent, wordToSearch, wordForReplace, filePath, 0);
                }
                break;
            case 3:
                fileContent = extractTextFromFile(filePath);
                printf("\n\nFILE CONTENT:\n\n%s\n\n", fileContent);
                break;
            default:
                break;
        }

     bufferWait();
    }
    while(choice != 0);   
}
