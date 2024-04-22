#include "methodTypes.h"

void runKnapSack() {
	int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("\n");

    int price[n], weight[n];
    for (i = 0; i < n; i++) {
	    printf("Enter the price for item %d:", i);
        scanf("%d", &price[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
	    printf("Enter the weight for item %d:", i);
        scanf("%d", &weight[i]);
    }

    printf("\n");
    
    int maxWeight; // Knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &maxWeight);

    printf("\nPrices: ");
    printArr(price, n);
    printf("Weights: ");
    printArr(weight, n);
    printf("maxWeight: %d\n\n", maxWeight);


    int choice;
    do
    {
    	printf("Select an option:\n1==Method 1\n2==Method 2\n3==Method 3\n0==Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);

	    double result;

		switch(choice) {
		        case 1:
		        	result = ks_methodOne(price, weight, maxWeight, n);
		            printf("\n\nThe optimal price (using method 1): %.2f\n\n", ceil(result * 100) / 100);
		            break;
		        case 2:
		        	result = ks_methodTwo(price, weight, maxWeight, n);
		            printf("\n\nThe optimal price (using method 2): %.2f\n\n", ceil(result * 100) / 100);
		            break;
		        case 3:
		        	result = ks_methodThree(price, weight, maxWeight, n);
		            printf("\n\nThe optimal price (using method 3): %.2f\n\n", ceil(result * 100) / 100);
		            break;
		        default:
		            break;
	    }
    }
	while(choice != 0);

    

}