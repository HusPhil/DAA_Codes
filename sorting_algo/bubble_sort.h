//#include "utils.h"

void bubble_sort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j+1] < arr[j]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void bubble_sort_pointers(int arr[], int size) {
    int itrCount = 1;
    int* itrA = arr;
    int* itrB ;
    int* end = arr + (size-1);

    while(itrA <= end) {
        itrB = arr;
        printf("ITERATION #%d", itrCount);
        while(itrB <= end - itrCount) {
            if(*itrB > *(itrB+1)) {
                swap(itrB, itrB+1);
            }
            itrB++;
            printf("\n");
            printArr(arr, size);
            printf("\n\n");

        }
        itrA++;
        itrCount++;
    }
}

