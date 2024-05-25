#include <stdio.h>
void findCommonElements(int A[], int M, int B[], int N) {
    int i = 0, j = 0;
    int result[M + N];
    int k = 0;
    while (i < M && j < N) 
    {
        if (A[i] < B[j])
            i++;
        else if (B[j] < A[i])
            j++;
        else 
        {
            result[k++] = A[i];
            i++;
            j++;
        }
    }
    if (k == 0)
        printf("No common elements found.\n");
    else 
   {
        for (int i = 0; i < k; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
}
int main() 
{
    int n,x;
    int A[n];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
          scanf("%d",&A[i]);
    }
    scanf("%d", &x);
    int B[x];
    for(int i=0;i<x;i++)
    {
          scanf("%d",&B[i]);
    }
    int M = sizeof(A) / sizeof(A[0]);
    int N = sizeof(B) / sizeof(B[0]);
    findCommonElements(A, M, B, N);
     return 0;
}









