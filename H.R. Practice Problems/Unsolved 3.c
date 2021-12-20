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

int q[5000],q2[5000];
int main()
{
    char str[5000],str2[5000];
    char qtr[5000],qtr2[5000];
    int i,j,i1,j1,f,sum=0;
    gets(str);
    gets(str2);

    for(i=0;i<strlen(str);i++){q[i]=0;}
    for(i=0;i<strlen(str2);i++){q2[i]=0;}

    for(i=0;i<strlen(str);i++)
    {
        if(q[i]==1){continue;}
        for(j=0;j<strlen(str2);j++)
        {
            if(q2[j]==1){continue;}
            if(str[i]==str2[j])
            {
               q[i]=1;
               q2[j]=1;
               for(int t=i+1;t<strlen(str);t++)
               {
                   if(str[i]==str[t]){q[t]=1;}
               }
               for(int z=j+1;z<strlen(str2);z++)
               {
                   if(str2[j]==str2[z]){q2[z]=1;}
               }
            }
        }
    }
    int b=0;
    for(i=0;i<strlen(str);i++)
    {
        if(q[i]==1)
        {
            qtr[b]=str[i];
            b++;
        }
    }
    qtr[b]='\0';
    b=0;
    for(i=0;i<strlen(str2);i++)
    {
        if(q2[i]==1)
        {
            qtr2[b]=str2[i];
            b++;
        }
    }
    qtr2[b]='\0';
    int max=0;
    for(i=0;i<strlen(qtr);i++)
    {
        for(j=0;j<strlen(qtr2);j++)
        {
            sum=0;
            if(qtr[i]==qtr2[j])
            {
                sum++;
                j1=j+1;
                i1=i+1;
                for(;i1<strlen(qtr);)
                {
                   for(j1=j+1;j1<strlen(qtr2);j1++)
                   {
                       if(qtr[i1]==qtr2[j1])
                       {
                         sum++;
                         i1++;
                       }
                   }
                   if(sum>max){max=sum;}
                   break;
                }

            }
        }
    }
    printf("%d\n",max);

}
