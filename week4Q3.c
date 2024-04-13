#include <stdio.h>
#include <stdlib.h>

int findKthSmallest(int * arr, int n, int k){
    if(k > n)
        return -1;
    
    int maxHeap[k];
    int h = 0;
    
    for(int i = 0; i < k; i++){
        maxHeap[h++] = arr[i];
        
       
        int j = h - 1;
        while(j > 0 && maxHeap[j] > maxHeap[(j - 1) / 2]){
            int temp = maxHeap[j];
            maxHeap[j] = maxHeap[(j - 1) / 2];
            maxHeap[(j - 1) / 2] = temp;
            j = (j - 1) / 2;
        }
    }
    
    for(int i = k; i < n; i++){
        if(arr[i] < maxHeap[0]){
            maxHeap[0] = arr[i];
            
            int j = 0;
            while(2 * j + 1 < h){
                int maxChildIndex = 2 * j + 1;
                if(2 * j + 2 < h && maxHeap[2 * j + 2] > maxHeap[maxChildIndex]){
                    maxChildIndex = 2 * j + 2;
                }
                if(maxHeap[j] >= maxHeap[maxChildIndex]){
                    break;
                }
                int temp = maxHeap[j];
                maxHeap[j] = maxHeap[maxChildIndex];
                maxHeap[maxChildIndex] = temp;
                j = maxChildIndex;
            }
        }
    }
    
    return maxHeap[0];
}

void  main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int k;
        scanf("%d", &k);
        int kth = findKthSmallest(arr, n, k);
        if(kth == -1){
            printf("Not Present\n");
        }
        else{
            printf("%d\n", kth);
        }
    }
    
}

