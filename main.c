#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "sorting_algo/run_sorting.h"
#include "searching_algo/run_search.h"
#include "searching_algo/searchInFile/run_fileSearch.h"
#include "knapSack/run_knapSack.h"
#include "fibonacci/run_Fibonacci.h"
#include "spanningTree/run_SpanningTree.h"

int main() {
    int choice;

    printf("Select an option:\n1==Sorting Algo\n2==Searching Algo\n3==File Search\n4==Knap Sack\n5==Fibonacci\n6==Spanning Tree\n0==Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch(choice) {
        case 1:
            runSorting();
            break;
        case 2:
            runSearch();
            break;
        case 3:
            runSearchInFile();
            break;
        case 4:
            runKnapSack();
            break;
        case 5:
            runFibonacci();
            break;
        case 6:
            runSpanningTree();
            break;
        default:
            printf("Not in the menu!");
            break;
    }


    return 0;
}


