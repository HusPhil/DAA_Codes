void insertion_sort(int arr[], int size) {
    int key;
    for(int i = 1; i < size; i++) {
        key = arr[i];
        for(int j = i - 1; j >= 0; j--) {
            if(arr[j] > key) {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
            printf("ri: %d|ti: %d|arr[ti]: %d|key: %d::NEW ARRAY: ", i, j, arr[j], key);
            printArr(arr, size);
            printf("\n");
        }
    }
}

void insertion_sortV2(int arr[], int size) {
    int key, ri, ti;
    for(ri = 1; ri < size; ri++) {
        key = arr[ri];
        ti = ri - 1;
        printf("ITERATION #%d\n", ri);
        while(ti >= 0 && arr[ti] > key){
            arr[ti+1] = arr[ti];
            ti--;
            printf("ri: %d|ti: %d|arr[ti]: %d|key: %d::NEW ARRAY: ", ri, ti, arr[ti], key);
            printArr(arr, size);
            printf("\n");
        }
        printf("\n");
        printArr(arr, size);
        printf("\n");
        printf("\n");
        arr[ti+1] = key;
    }
}

void insertion_sort_pointers(int arr[], int size) {
    int iterationCount = 1;
    int key;
    int* pos;
    int* start = arr;
    int* end = arr + (size - 1);

    while (start < end) {
        key = *(start+1);
        pos = start;
        printf("\n[ITERATION COUNT: %d]\n", iterationCount);
        while(pos >= arr && *pos > key) {
            *(pos+1) = *pos;
            pos--;
        }
        printArr(arr, size);
        printf("\n");
        *(pos+1) = key;
        iterationCount++;
        start++;
    }

}