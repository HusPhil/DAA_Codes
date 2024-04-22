#include <stdio.h>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort_mine.h"
#include "quick_sort.h"


void runSorting() {

    int choice;
    do{
    system("cls");
    printf("Select sorting algo:\n1 == Bubble Sort\n2 == Selection Sort\n3 == Insertion Sort\n4 == Merge Sort\n5 == Quick Sort\n0 == Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if(choice == 0) return;
    if(choice > 5) {
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

    switch(choice) {
    	
        case 1: 
            bubble_sort_pointers(arr, size);
            break;
        case 2: 
            selection_sort_pointers(arr, size);
            break;
        case 3: 
	       insertion_sort_pointers(arr, size);
            break;
        case 4:
            mergeSort(arr, 0, size - 1);
            break;
        case 5:
            quickSort(arr, 0, size - 1);
            break;
        default:
            printf("Invalid choice");
            return;
    }
    printf("\nSORTED ARRAY: ");
    printArr(arr, size);
    printf("\n\n");
    bufferWait();
    }
    while(choice != 0);
    return;   
}
