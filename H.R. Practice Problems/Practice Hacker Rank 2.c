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
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int x=x1+y1;
    int X=x2+y2;
    if(x>X)
    {
        while(1)
        {
            x=x+y1;
            X=X+y2;
            if(X==x){printf("YES");break;}
            else if(x<X){printf("NO");break;}
        }
    }
    else if(x<X)
    {
        while(1)
        {
            x=x+y1;
            X=X+y2;
            if(X==x){printf("YES");break;}
            else if(X<x){printf("NO");break;}
        }
    }
    else{printf("YES");}
}
