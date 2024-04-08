#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key, int *comparisons) {
    if (right >= left) {
        (*comparisons)++; 
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            (*comparisons)++; 
            return mid;

        if (arr[mid] > key)
            (*comparisons)++; 
            return binarySearch(arr, left, mid - 1, key, comparisons);

        return binarySearch(arr, mid + 1, right, key, comparisons);
    }

    return -1; // Key element not found
}

int main() {
   int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
    int key;
    scanf("%d",&key);
    int comparisons = 0;
    int result = binarySearch(arr, 0, n - 1, key, &comparisons);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Present at  %d\n", result);

    printf("comparisons: %d\n", comparisons);
   
}
}
