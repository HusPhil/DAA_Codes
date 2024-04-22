void selection_sort(int arr[], int size) {
    int min;
    for(int i = 0; i < size; i++) {
        min  = i;
        printf("ITERATION NUM #%d\n\n", i+1);
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        printf("i: %d, j: %d, arr[i]: %d, arr[j]: %d min: %d\n", i, j, arr[i], arr[j], arr[min]);
        }
        swap(&arr[min], &arr[i]);       
        printArr(arr, size);
        printf("\n\n");
    }
}

void selection_sortV2(int arr[], int size) {
    int min;
    int new_min;
    for(int i = 0; i < size; i++) {
        min = i;
        new_min = i;
        printf("ITERATION NUM #%d: ", i+1);
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[new_min]) {
                new_min = j;
            }
        }
        swap(&arr[min], &arr[new_min]);
        printArr(arr, size);
        printf("\n\n");
    }
}

void selection_sort_pointers(int arr[], int size) {
    int itrCount = 1;
    int* min;
    int* start = arr;
    int* itr = start;
    int* end = (arr+(size-1));
    while(start <= end) {
        itr = start;
        min = start;
        while(itr <= end) {
            if(*itr < *min) {
                min = itr;
            }
            itr++;
        }
        printf("ITERATION # %d\nmin: %d ", itrCount, *min);
        printArr(arr, size);
        printf("\n\n");
        swap(min, start);
        itrCount++;
        start++;
    }
}