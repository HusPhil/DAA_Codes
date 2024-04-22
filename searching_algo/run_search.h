#include <stdio.h>
#include "binary_search.h"
#include "linear_search.h"

void runSearch() {
    int choice;
    int foundIndex = -1;
    do{
    system("cls");
    printf("Select searching algo: \n1 == Linear Search\n2 == Binary Search\n0 == Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if(choice == 0) return;
    if(choice > 2 || choice < 0) {
        printf("Invalid choice");
        return;
    }

    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Enter element value at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size - 1);

    printArr(arr, size);

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    

    switch(choice) {
        case 1: 
            foundIndex = linear_search(arr, size, target);
            break;
        case 2: 
            foundIndex = binary_search(arr, size, target);         
            break;
        default:
            printf("Invalid choice");
            return;
        }

    

    if(foundIndex == -1) {
        printf("Target was not found.\n"); 
    } 
    else {
        printf("Target was found at index %d.\n\n\n", foundIndex);  
    }
    
    bufferWait();
    }
    while(choice != 0);
    return;
}
