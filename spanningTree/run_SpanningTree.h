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
        {0, 10, 1, 5, 0, 0, 0},
        {10, 0, 8, 0, 1, 1, 0},
        {1, 8, 0, 3, 0, 6, 0},
        {5, 0, 3, 0, 4, 0, 0},
        {0, 1, 0, 4, 0, 2, 6},
        {0, 1, 6, 0, 2, 0, 0},
        {0, 0, 0, 0, 6, 0, 0},
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
