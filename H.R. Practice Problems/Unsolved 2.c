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
int main()
{
    int n,k,arr[100000],qrr[100000],ctr[100000];
    scanf("%d",&n);
    scanf("%d",&k);
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        qrr[i]=arr[i];
        ctr[i]=0;
    }
    int max=0,v=0,flag=0;
    for(i=0;i<n;i++)
    {
        if(ctr[i]==-1){continue;}
        for(j=i+1;j<n;j++)
        {
            int t=arr[i]+arr[j];
            if(t%k==0)
            {
                ctr[j]=-1;
               printf("%d+%d=%d No\n",arr[i],arr[j],t);
            }
            else
            {
                printf("%d+%d=%d Yes\n",arr[i],arr[j],t);
            }
        }
        v++;
        ctr[i]=1;
        if(flag=0){i=0;flag=1;v=0;}
    }
    for(int b=0;b<n;b++)
    {
        printf("%d    ",ctr[b]);
    }
    printf("%d",v);
}
