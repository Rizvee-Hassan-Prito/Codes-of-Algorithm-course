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

typedef struct Time
{
    int st;
    int ft;
}time;
void merger(time left[],int leftsize,time right[],int rightsize,time arr[])
{
    int it1=0,it2=0,it3=0;
    while(it1<leftsize && it2<rightsize)
    {
        if(left[it1].ft<right[it2].ft)
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

int mergeSort(time arr[],int n)
{
    if(n==1)return;
    time left[n/2],right[n-n/2];int i,j;
    for(i=0,j=n/2; i<n/2,j<n; i++,j++)
    {
        left[i]=arr[i];
        right[i]=arr[j];
    }
    mergeSort(left,n/2);
    mergeSort(right,n-n/2);
    merger(left,n/2,right,n-n/2,arr);
}

void maxTaskSelection(time task[],int n)
{
    mergeSort(task,n);
    int last=0,cnt=1;
    for(int i=1;i<=n-1;i++)
    {
        if(task[last].ft<=task[i].st)
        {
            cnt++;
            last=i;
        }
    }
    printf("%d",cnt);
}

int main()
{
    // Write your code here
    int n;
    scanf("%d",&n);
    time t[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&t[i].st,&t[i].ft);
    }
    maxTaskSelection(t,n);
    return 0;
}

