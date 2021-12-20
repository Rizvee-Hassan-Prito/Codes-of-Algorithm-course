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
   char str[100];
   gets(str);
   int n,arr[100];
   scanf("%d",&n);
   int i,j;
   for(i=0;i<n*2;i++)
   {
       scanf("%d",&arr[i]);
       arr[i]-=1;
   }
   int len=strlen(str);
   int n1=0;
   while(n1<=n)
   {
     int x=0;
     char str2[100];
     for(i=arr[n1];i<=arr[n1+1];i++)
     {
        str2[x]=str[i];
        x++;
     }
     int max_cnt=0;
     int same=0;
     for(i=0;i<x;i++)
     {
        int cnt=0;
        if(str2[i]<97){continue;}
        for(j=i+1;j<x;j++)
        {
            if(str2[i]==str2[j])
            {
                str2[j]='A';
                cnt++;
            }
        }
        cnt++;
        if(max_cnt<cnt){max_cnt=cnt;same=0;}
        //else if(max_cnt==cnt){same++;}
     }
     n1+=2;
   }
}
