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


int ap,on;
void countApplesAndOranges (int s,int t,int a,int b,int app[],int orr[])
{
    int cntapp=0;
    for(int i=0;i<ap;i++)
    {
        app[i]+=a;
        if(s<=app[i] && app[i]<=t)
        {
            cntapp++;
        }
    }
    int cntor=0;
    for(int i=0;i<on;i++)
    {
        orr[i]+=b;
         if(s<=orr[i] && orr[i]<=t)
        {
            cntor++;
        }
    }
    printf("%d\n",cntapp);
    printf("%d\n",cntor);
}

int main()
{
    int s,t;
    scanf("%d%d",&s,&t);
    int al,ol;
    scanf("%d%d",&al,&ol);
    scanf("%d%d",&ap,&on);
    int app[ap],or[on];
    int i,j;
    for(i=0;i<ap;i++)
    {
        scanf("%d",&app[i]);
    }
    for(i=0;i<on;i++)
    {
        scanf("%d",&or[i]);
    }
    countApplesAndOranges(s,t,al,ol,app,or);
}
