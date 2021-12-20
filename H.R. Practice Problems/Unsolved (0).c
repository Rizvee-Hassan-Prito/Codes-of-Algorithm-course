
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
   int i,j,n,k,k1,g=0;
   scanf("%d",&n);
   char str[10][100000],qtr[10][100000];
   for(i=0;i<n;i++)
   {
       scanf("%s",str[i]);
       scanf("%s",qtr[i]);
   }
    for (i=0;i<n;i++)
    {
       int f=0;
       if(strlen(qtr[i])==1)
           {
               f=1;
            for(k1=0;k1<strlen(str[i]);k1++)
            {
               printf("%d ",k1);
            }
           }
       for(k=0;k<strlen(str[i])-1;k++)
       {
           int m,sum=0,v=0;
           for(k1=k;k1<strlen(str[i]);k1++)
           {
               if(v==0){m=k1;}
               if(str[i][k1+1]=='\0' && qtr[i][v+1]!='\0'){break;}
               if(str[i][k1]==qtr[i][v])
               {
                 sum++;
                 if(sum==strlen(qtr[i])-1)
                 {
                   f=1;
                   printf("%d ",m);
                   break;
                 }
               }
               if(v==strlen(qtr[i])-1){break;}
               v++;
           }
       }
       if(f==0){printf("No Match!");}
       printf("\n");
   }
}
