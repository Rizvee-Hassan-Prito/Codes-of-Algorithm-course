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

void findintersection(int a[],int as,int b[],int bs,int c[])
{
    int inda=0,indb=0,indc=0;
    while(inda<as&&indb<bs)
    {
        if(a[inda]==b[indb])
        {
            c[inda]=a[inda]
            inda++;
            indc++;
            indb++;
        }
        else if (a[inda]>b[indb])
        {
            indb++;
        }
        else
        {
            inda++;
        }
    }
