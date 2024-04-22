void merge(int arr[], int li, int mi, int ri) {
    // create sub arrays
    int i, j, k;

    int leftSize = mi - li + 1;
    int rightSize = ri - mi;
    
    int left[leftSize];
    int right[rightSize];

    //copy data to the sub array
    for(i = 0; i < leftSize; i++) {
        left[i] = arr[li + i];
    }
    for(j = 0; j < rightSize; j++) {
        right[j] = arr[mi + 1 + j];
    }
    printArr(left, leftSize);
    printArr(right, rightSize);
    

    //combine the 2 subarray while sorting it
    i = j = 0;
    k = li;

    while(i < leftSize && j < rightSize) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //handle the remaining data that might not be added
    while(i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[], int li, int ri) {
    if(li < ri) {
        int mi =  (li + ri)/2;

        mergeSort(arr, li, mi);
        mergeSort(arr, mi+1, ri);
        merge(arr, li, mi, ri);
    }
}