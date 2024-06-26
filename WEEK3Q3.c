#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
	{
        if (arr[j] < pivot) 
		{
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
	{
        int n;
        scanf("%d", &n);
        int nums[n];
        for (int i = 0; i < n; i++) 
		{
            scanf("%d", &nums[i]);
        }
        quickSort(nums, 0, n - 1);
        int dupe = 0;
        for (int i = 0; i < n - 1; i++) 
		{
            if (nums[i] == nums[i + 1]) 
			{
                dupe = 1;
                break;
            }
        }
        if (dupe) 
		{
            printf("YES\n");
        } else 
		{
            printf("NO\n");
        }
    }
    return 0;
}

