int fibGreedy(int n) {
    static int ctr = 0;
    ctr++;
    printf("call count: %d\n", ctr);

    if(n<=1) {
        return n;
    }
    else return fibGreedy(n-2) + fibGreedy(n-1);
}

int fibDynamic(int n) {
    static int ctr = 0;
    ctr++;
    printf("call count: %d\n", ctr);

    int result;
    
    
    if(n<=1) {
        return n;
    }
    
    int *fib = (int*) malloc((n+1) * sizeof(int));

    if (fib == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); 
    }

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf("iteration count: %d\n", i-1);
    }

    result = fib[n];
    free(fib);
    return result;

}
