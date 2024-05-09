#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int* comparisons, int* swaps) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
      
        if (arr[j] < pivot) {
            (*comparisons)++;
            i++; 
            (*swaps)++;
            swap(&arr[i], &arr[j]);
        }
    }
    (*swaps)++;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int randomizedPartition(int arr[], int low, int high, int* comparisons, int* swaps) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    (*swaps)++;
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high, comparisons, swaps);
}

void quicksort(int arr[], int low, int high, int* comparisons, int* swaps) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high, comparisons, swaps);

        quicksort(arr, low, pi - 1, comparisons, swaps);
        quicksort(arr, pi + 1, high, comparisons, swaps);
    }
}


void main() {
    int t;
    scanf("%d",&t);

    while(t!=0){

        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    int comparisons = 0, swaps = 0;
    quicksort(arr, 0, n - 1, &comparisons, &swaps);

     for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    t--;
}
}