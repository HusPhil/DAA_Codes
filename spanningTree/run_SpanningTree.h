#include <stdio.h>
#include "primsAlgo.h"


void runSpanningTree() {

    int choice;
    do{
    system("cls");
    printf("Select sorting algo:\n1 == Prim's Algorithm\n2 == HAks's Algorithm\n0 == Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if(choice == 0) return;
    if(choice > 2) {
        printf("Invalid choice");
        return;
    }

    int V = 6;
    // printf("Enter array size: ");
    // scanf("%d", &size);

    // int arr[size];
    // for(int i = 0; i < size; i++) {
    //     printf("Enter element value at index %d: ", i);
    //     scanf("%d", &arr[i]);
    // }

    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 75, 9, 0, 9},
        {75, 0, 95, 51, 0},
        {9, 95, 0, 19, 42},
        {0, 51, 19, 0, 31},
        {9, 0, 42, 31, 0},
    };

    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    
    printf("Minimum Spanning Tree:\n");
    
    switch(choice) {
    	
        case 1: 
            // bubble_sort_pointers(arr, size);
            primMST(graph, numVertices);
            break;
        case 2: 
            // selection_sort_pointers(arr, size);
            break;
        default:
            printf("Invalid choice");
            return;
    }


    printf("\n\n");
    bufferWait();


    }
    while(choice != 0);
    return;   
}
