#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

   char str[10],gtr[10];
   gets(str);
   gets(gtr);
   int len=strlen(str),j=0,cnt=0;
   int len2=strlen(gtr);
   for(int i=0;i<len;i++)
   {
       str[i]=tolower(str[i]);
   }
   for(int i=0;i<len2;i++)
   {
       gtr[i]=tolower(gtr[i]);
   }
   for(int i=0;i<len;i++)
   {
       if(str[i]==gtr[j])
       {
         cnt++;
         j++;
       }
   }
   if(cnt==len2){printf("1\n");}
   else printf("0\n");
   return 0;
}
