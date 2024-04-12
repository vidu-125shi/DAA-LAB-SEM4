#include <stdio.h>
#include <stdlib.h>

void selection(int *arr, int n) 
{
    int comparisions = 0;
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minindex]) 
            {
                minindex = j;
            }
            comparisions++;
        }
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
        swaps++;
    }
    printf("%d %d\n", swaps, comparisions);
}

void main() 
{
    int t;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

    selection(arr, n);

    for (int i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }
  
}
}

