//samantha rodriguez lab 7
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int n) {

    //allocates memory and copies array to data array, initializes swap counter array to 0
    element* swaps = (element*)malloc(sizeof(element)*n);
    for(int i = 0; i < n; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }

    int total = 0;

    //Bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                
                //counts swap for current index and the one it is getting swapped with
                swaps[j].numswaps++;
                swaps[j + 1].numswaps++;
                
                //calls swap function
                swap(&swaps[j], &swaps[j + 1]);
                
            }
            
        }
    
    }

    for(int i=0;i<n;i++) {
    printf("%d: Number of times %d is swapped: %d\n", swaps[i].data,swaps[i].data,swaps[i].numswaps);
    //each array element added together for total number of swaps
    total += swaps[i].numswaps;
    
    }
    printf("Total # of swaps: %d", total/2);
    
}

element* numSwapsSelectionSort(int* arr, int n) {

    //allocates memory and copies array to data array, initializes swap counter array to 0
    element* swaps = (element*)malloc(sizeof(element)*n);
    for(int i = 0; i < n; i++){
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    int min,total = 0;

    //Selection sort algorithm
    for(int i=0;i<n-1;i++) {
        min = i;
        
        for(int j=i+1;j<n;j++) {
            if(swaps[j].data<swaps[min].data) 
            min = j;
            
        }

        //if minimum is not the current index
        if (min!=i) {
        //elements that are swapped, get incremented
        swaps[i].numswaps++;
        swaps[min].numswaps++;

        //calls swap function
        swap(&swaps[min], &swaps[i]);  
        }  
    }

    for(int i=0;i<n;i++) {
    printf("%d: Number of times %d is swapped: %d\n", swaps[i].data,swaps[i].data,swaps[i].numswaps);
    //each array element added together for total number of swaps
    total += swaps[i].numswaps;
    }

    printf("Total # of swaps: %d", total/2);

}

//swapping algorithm
int swap(element* element1,element* element2) {
     element tmp = *element1;
    *element1 = *element2;
    *element2 = tmp;
}


int main() {

    //given arrays
    int arr1[] = {97,16,45,63,13,22,7,58,72};
    int arr2[] = {90,80,70,60,50,40,30,20,10};

    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);


    printf("\nArray 1 Bubble Sort\n");
    element* arr1Bubble = numSwapsBubbleSort(arr1, n1);
    free(arr1Bubble);
    printf("\nArray 2 Bubble Sort\n");
    element* arr2Bubble = numSwapsBubbleSort(arr2, n2);
    free(arr2Bubble);

    printf("\nArray 1 Selection Sort\n");
    element* arr3Selection = numSwapsSelectionSort(arr1, n1);
    free(arr3Selection);
    printf("\nArray 2 Selection Sort\n");
    element* arr4Selection = numSwapsSelectionSort(arr2, n2);
    free(arr4Selection);
   
}