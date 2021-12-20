#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define N 100010
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

int n,e;
int cnt=0,f=0;
vector <int>adj[N];
vector <int>trnpse[N];
vector<int>order;
int col[N];
int col2[N];
void dfs(int node)
{
   int i;
   col[node]=GREY;
   for(i=0;i<adj[node].size();i++)
   {
       int v=adj[node][i];
       if(col[v]==WHITE)
       {
           dfs(v);
       }
   }
   col[node]=BLACK;
   order.push_back(node);
}
void dfs2(int node)
{
   int i;
   col2[node]=GREY;
   cnt++;
   for(i=0;i<trnpse[node].size();i++)
   {
       int v=trnpse[node][i];
       if(col2[v]==WHITE)
       {
           dfs2(v);
       }
   }
   col2[node]=BLACK;
}
int main() {
    int i,u,v;
    scanf("%d%d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        trnpse[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        col[i]=WHITE;
        col2[i]=WHITE;
    }
    for(i=1;i<=n;i++)
    {
        if(col[i]==WHITE)
        {
            dfs(i);
            f++;
        }
    }
    reverse(order.begin(),order.end());
    for(i=0;i<order.size();i++)
    {
        int k=order[i];
        if(col2[k]==WHITE)
        {
            dfs2(k);
            break;
        }
    }
    if(f>1){cnt=0;}
    printf("%d",cnt);
    return 0;
}
/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define N 100010
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

int n,e;
int cnt=0,f=0,c=0,counter=0;
vector <int>adj[N];
vector <int>trnpse[N];
vector<int>order;
vector<int>cmpnt[N];
int col[N];
int col2[N];
void dfs(int node)
{
   int i;
   counter++;
   col[node]=GREY;
   for(i=0;i<adj[node].size();i++)
   {
       int v=adj[node][i];
       if(col[v]==WHITE)
       {
           dfs(v);
       }
   }
   col[node]=BLACK;
   order.push_back(node);
}

void dfs2(int node)
{
   int i;
   col2[node]=GREY;
   for(i=0;i<trnpse[node].size();i++)
   {
       int v=trnpse[node][i];
       if(col2[v]==WHITE)
       {
           dfs2(v);
       }
   }
   col2[node]=BLACK;
   cmpnt[c].push_back(node);
}

int main() {
    int i,u,v;
    scanf("%d%d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        trnpse[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        col[i]=WHITE;
        col2[i]=WHITE;
    }
    for(i=1;i<=n;i++)
    {
        if(col[i]==WHITE)
        {
            dfs(i);
            f++;
        }
    }
    reverse(order.begin(),order.end());
    for(i=0;i<order.size();i++)
    {
        int k=order[i];
        if(col2[k]==WHITE)
        {
            dfs2(k);
            c++;
        }
    }
    for(i=0;i<c;i++)
    {
        for(int j=1;j<=n;j++){col[j]=WHITE;}
        printf("%d ",cmpnt[i][0]);
        dfs(cmpnt[i][0]);
        if(n==counter){cnt+=counter;}
        counter=0;
    }
    //if(f>1){cnt=0;}
    printf("%d",cnt);
    return 0;
}*/


