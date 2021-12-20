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
    long long int n,i,j;
    scanf("%lld",&n);
    long long int rank[n];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&rank[i]);
    }
    long long int m;
    scanf("%lld",&m);
    long long int player[m];
    for(i=0;i<m;i++)
    {
        scanf("%lld",&player[i]);
    }
    long long int ranking[n],k=0,sum=0,x=0;
    for(i=0;i<n;i+=sum)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            if(rank[i]==rank[j])
            {
                sum++;
            }
            else{break;}
        }
        int sum2=sum;
        while(sum2!=0)
        {
            ranking[k]=x+1;
            k++;
            sum2--;
        }
        x++;

    }
    j=n-1;
    for(i=0;i<m;i++)
    {
        if(j<0){break;}
        for(;j>=0;j--)
        {
            if(player[i]<rank[j])
            {
                printf("%lld\n",ranking[j]+1);
                break;
            }
            else if (player[i]==rank[j])
            {
                printf("%lld\n",ranking[j]);
                break;
            }
            else if (player[i]>rank[0])
            {
                printf("%lld\n",ranking[0]);
                break;
            }
        }
    }
}

