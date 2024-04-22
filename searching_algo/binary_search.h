
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int pass = 0;

    int targetIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        printf("Pass: %d || Start: %d || Mid: %d || End: %d\n\n", pass, left, mid, right);
       
        if (arr[mid] == target){
            targetIndex = mid;
            pass++;
            break;
        }
        

      
        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;

        pass++;

    }

    printf("Time complexity log(n): %d\n[n = %d]\n\n", pass, size);

    return targetIndex;
}
