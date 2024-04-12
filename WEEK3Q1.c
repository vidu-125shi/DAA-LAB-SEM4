#include <stdio.h>
#include <stdlib.h>

void insertion(int *arr, int size) {
    int comparisions = 0;
    int swap = 0;
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                comparisions++;
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
        swap++;
    }
    swap += comparisions;
    printf("%d %d\n", comparisions, swap);
}

void main() {
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    insertion(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    }
}

