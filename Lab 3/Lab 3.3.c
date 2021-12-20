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

void NODandSOD(int n)
{
    int arr[n],sod[n],i,j;
    for(i=1;i<=n;i++)
    {
        arr[i]=0;
        sod[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j+=i)
        {
            arr[j]++;
            sod[j]+=i;
        }

    }
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",arr[i],sod[i]);
    }
}

int main()
{
    // Write your code here
    int n;
    scanf("%d",&n);
    NODandSOD(n);
    return 0;
}


