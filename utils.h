void swap(int *a, int *b) {
    int holder = *a;
    *a = *b;
    *b = holder;
}

void printArr(int arr[], int size) {
    printf("\n[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != size - 1)
        printf(",");
    }
        printf("]\n");
}

void bufferWait() {
    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Wait for the user to press Enter
    printf("Press Enter to continue...");
    getchar(); // Wait for Enter key press
}