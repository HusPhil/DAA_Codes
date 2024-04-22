#include "fibonacci.h"

void runFibonacci() {
	int n;
    printf("Enter which nth term: ");
    scanf("%d", &n);
    printf("\n");

    if(n < 0) {
    	printf("\n\nInvalid input.\n\n");		  
    	return;      		
	}
    int choice;

    do
    {
    	printf("Select an option:\n1==Greedy method\n2==Dynamic method\n0==Exit\n");
	    printf("Enter your choice: ");
	    scanf("%d", &choice);

	    int result;
    	

		switch(choice) {
		        case 1:
		        	result = fibGreedy(n);
					printf("\n\nThe the nth term is: %d\n\n", result);
		            break;
		        case 2:
		        	result = fibDynamic(n);
		            printf("\n\nThe the nth term is: %d\n\n", result);
		        	break;
		        default:
		            break;
	    }
    }
	while(choice != 0);

    

}