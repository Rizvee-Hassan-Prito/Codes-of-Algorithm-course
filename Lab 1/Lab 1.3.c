#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merger(int left[],int leftsize,int right[],int rightsize,int arr[])
{
    int it1=0,it2=0,it3=0;
    while(it1<leftsize && it2<rightsize)
    {
        if(left[it1]<right[it2])
        {
           arr[it3]=left[it1];
           it1++;
           it3++;
        }
        else
        {
           arr[it3]=right[it2];
           it2++;
           it3++;
        }
    }
        while(it2<rightsize)
        {
            arr[it3]=right[it2];
            it3++;
            it2++;
        }
        while(it1<leftsize)
        {
            arr[it3]=left[it1];
            it3++;
            it1++;
        }
}

int mergeSort(int arr[],int n)
{
    if(n==1)return;
    int left[n/2],right[n-n/2],i,j;
    for(i=0,j=n/2; i<n/2,j<n; i++,j++)
    {
        left[i]=arr[i];
        right[i]=arr[j];
    }
    mergeSort(left,n/2);
    mergeSort(right,n-n/2);
    merger(left,n/2,right,n-n/2,arr);
}

int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
