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

int binarySearch(int arr[],int n,int x)
{
    int h=n-1,l=0,m;
    while(h>=l)
    {
        m=(h+l)/2;
        if(arr[m]==x){return m;}
        if(arr[m]>x){h=m-1;}
        if(arr[m]<x){l=m+1;}
    }
    return -1;
}

int main()
{
    // Write your code here
    int n,i,k,x,v;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&x);
        v=binarySearch(arr,n,x);
        printf("%d\n",v);
    }
    return 0;
}

