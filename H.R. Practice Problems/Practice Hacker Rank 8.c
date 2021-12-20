#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char str[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%c",str[i]);
    }
}
void cpy(char qtr[],char str[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        qtr[i]=str[i];
    }
}
void rev(char str[],int n)
{
    int i;
    char qtr[100000];
    for(i=0;i<n;i++)
    {
        qtr[i]=str[n-1-i];
    }
    for(i=0;i<n;i++)
    {
        str[i]=qtr[i];
    }
}
int main()
{
    char str[100],str2[100000],qtr[100000],c;
    int n,k,i;
    scanf("%d %d %s", &n, &k, str);
    cpy(qtr,str,n);
    rev(str,n);
    cpy(str2,str,n);
    int same=0;
    if(strcmp(str2,qtr)==0)
    {
        same=1;
    }

    if(same==1 && k==0){print(qtr,n);return 0;}
    else if(same!=1&&k==0){printf("-1");return 0;}
    if(k>n)
    {
    for(i=0;i<k;i++)
    {
      if(qtr[i]!='9')
      {
        qtr[i]='9';
      }
    }
    print(qtr,n);
    return 0;
    }
    if(k==n)
    {
    for(i=0;i<k;i++)
    {
        if(qtr[i]!='9')
        {
            qtr[i]='9';
        }
    }
    print(qtr,n);
    return 0;
    }
    if(same==1)
    {
        if(n%2!=0)
        {
            if(qtr[n/2]!='9'){qtr[n/2]='9';}
            else
            {qtr[n/2]='8';}
            k--;
            for(i=0;i<n;i++)
            {
                if(k<0){printf("-1");break;}
                if(k==0){printf(qtr,n);break;}
                if(qtr[i]=='9')
                {
                    qtr[i]='8';
                    qtr[n-1-i]='8';
                    k=k-2;
                }
                else
                {
                    qtr[i]='9';
                    qtr[n-1-i]='9';
                    k=k-2;
                }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(k<0){printf("-1");break;}
                if(k==0){print(qtr,n);break;}
                if(qtr[i]=='9')
                {
                    qtr[i]='8';
                    qtr[n-1-i]='8';
                    k=k-2;
                }
                else
                {
                    qtr[i]='9';
                    qtr[n-1-i]='9';
                    k=k-2;
                }
            }
        }
    }
    else
    {
        if(n%2==0)
        {
            int arr[n];
            for(i=0;i<n;i++){arr[i]=0;}
            while(k>=0)
            {
                int g=0;
              for(i=0;i<n/2;i++)
              {
                if(qtr[i]!=qtr[n-i-1])
                {
                    arr[i]=1;
                    arr[n-i-1]=1;
                    if(qtr[i]>qtr[n-i-1]){qtr[n-i-1]=qtr[i];}
                    else{qtr[i]=qtr[n-i-1];}
                    k--;
                    g=1;
                }
              }
              if(k==0){print(qtr,n);return 0;}
              if(k%2!=0)
              {
                  for(i=0;i<n/2;i++)
                  {
                    if(arr[i]==1)
                    {
                      arr[i]=2;
                      if(qtr[i]=='9')
                      {
                        qtr[i]='8';
                        qtr[n-1-i]='8';
                      }
                     else
                      {
                        qtr[i]='9';
                        qtr[n-1-i]='9';
                      }
                      k--;g=1;
                      break;
                    }
                  }
              }
              if(k==0){print(qtr,n);return 0;}
              if(k%2==0)
              {
                  for(i=0;i<n/2;i++)
                  {
                    if(arr[i]==0)
                    {
                      arr[i]=3;
                      if(qtr[i]=='9')
                      {
                        qtr[i]='8';
                        qtr[n-1-i]='8';
                      }
                     else
                      {
                        qtr[i]='9';
                        qtr[n-1-i]='9';
                      }
                      k=k-2;g=1;
                      break;
                    }
                  }
              }
              if(k==0){print(qtr,n);return 0;}
              if(g==1){printf("-1");return 0;}
            }
            printf("-1");return 0;
        }
        else
        {
            int arr[n];
            for(i=0;i<n;i++){arr[i]=0;}
            while(k>=0)
            {
              int g=0;
              for(i=0;i<n/2;i++)
              {
                if(qtr[i]!=qtr[n-i-1])
                {
                    arr[i]=1;
                    arr[n-i-1]=1;
                    if(qtr[i]>qtr[n-i-1]){qtr[n-i-1]=qtr[i];}
                    else{qtr[i]=qtr[n-i-1];}
                    k--;
                    g=1;
                }
              }
              if(k==1){qtr[n/2]=qtr[n/2]+1;k--;print(qtr,n);return 0;}
              if(k==0){print(qtr,n);return 0;}
              if(k%2!=0)
              {
                  for(i=0;i<n/2;i++)
                  {
                    if(arr[i]==1)
                    {
                      arr[i]=2;
                      if(qtr[i]=='9')
                      {
                        qtr[i]='8';
                        qtr[n-1-i]='8';
                      }
                     else
                      {
                        qtr[i]='9';
                        qtr[n-1-i]='9';
                      }
                      k--;g=1;
                      break;
                    }
                  }
              }
              if(k==1){qtr[n/2]=qtr[n/2]+1;k--;print(qtr,n);return 0;}
              if(k==0){print(qtr,n);return 0;}
              if(k%2==0)
              {
                  for(i=0;i<n/2;i++)
                  {
                    if(arr[i]==0)
                    {
                      arr[i]=3;
                      if(qtr[i]=='9')
                      {
                        qtr[i]='8';
                        qtr[n-1-i]='8';
                      }
                     else
                      {
                        qtr[i]='9';
                        qtr[n-1-i]='9';
                      }
                      k=k-2;g=1;
                      break;
                    }
                  }
              }
              if(k==1){qtr[n/2]=qtr[n/2]+1;k--;print(qtr,n);return 0;}
              if(k==0){print(qtr,n);return 0;}
              if(g==1){printf("-1");return 0;}
            }
            printf("-1");return 0;
        }
    }
}
