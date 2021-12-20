
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int arr[]={500,100,50,20,10,5,2,1};
    int x,cnt=0;
    scanf("%d",&x);
    for(int i=0;i<8;i++)
    {
        int m=x/arr[i];
        if(m>0)
        {
            while(m!=0)
            {
               x=x-arr[i];
               m--;
               cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
