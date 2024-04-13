#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int l, int mid, int r, int *comparisons, int *inversions) {
    int L = mid - l + 1;
    int R = r - mid;
    int *left = (int *)malloc(L * sizeof(int));
    int *right = (int *)malloc(R * sizeof(int));

    for (int i = 0; i < L; i++)
        left[i] = a[l + i];
    for (int j = 0; j < R; j++)
        right[j] = a[mid + 1 + j];

    int i = 0, j = 0;
    int k = l;

    while (i < L && j < R) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
            (*inversions)++;
        }
        k++;
        (*comparisons)++;
    }

    while (i < L) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < R) {
        a[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void mergeSort(int *a, int l, int r, int *comparisons, int *inversions) {
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    mergeSort(a, l, mid, comparisons, inversions);
    mergeSort(a, mid + 1, r, comparisons, inversions);

    merge(a, l, mid, r, comparisons, inversions);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int *a = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int comparisons = 0;
        int inversions = 0;

        mergeSort(a, 0, n - 1, &comparisons, &inversions);

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
        printf("Comparisons = %d\n", comparisons);
        printf("Inversions = %d\n", inversions);

        free(a);
    }

    return 0;
}

