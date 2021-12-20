#include <stdio.h>
#include <stdlib.h>
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

/* Driver program to test above functions */
int main()
{
    int arr[] = { 5, 2, 1, 4, 3, 7, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf(" Number of inversions are %d \n",
           getInvCount(arr, n));
    return 0;
}
