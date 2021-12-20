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


int fastExpo(int a,int b)
{
    if (b==0){return 1;}
    if (b==1){return a;}
    int r=fastExpo(a,b/2);
    if (b%2==1){return a*r*r;}
    return r*r;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("%d^%d=%d\n",a,b,fastExpo(a,b));
    return 0;
}

