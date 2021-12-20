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
    // Write your code here
    int i,n,j=0,max_ctg=0;
    long long int x;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%lld",&x);
    for(i=0;i<n;i++)
    {
        int ctg=0,sum=0;
        for(j=i;j<n;j++)
        {
           sum+=arr[j];
           if(sum<=x)
           {
               ctg++;
           }
        }
        if(max_ctg<ctg){max_ctg=ctg;}
    }
    printf("%d\n",max_ctg);
    return 0;
}
