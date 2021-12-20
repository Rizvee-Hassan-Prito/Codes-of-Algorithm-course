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

void sieve(int n)
{
    int arr[n],i,j,sum=0;
    for(i=1;i<=n;i++)
    {
        arr[i]=1;
    }
    arr[0]=0;
    arr[1]=0;
    sum=2;
    for(i=2;i<=n;i++)
    {
        if(arr[i]==1)
        {
            printf("%d\n",i);
            for(j=i*2;j<=n;j+=i)
                arr[j]=0;
        }
    }
}

int main()
{
    // Write your code here
    int n;
    scanf("%d",&n);
    sieve(n);
    return 0;
}

