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
        }
    }
    reverse(order.begin(),order.end());
    int cnt=0;
    for(i=0;i<order.size();i++)
    {
        int k=order[i];
        if(col2[k]==WHITE)
        {
            dfs2(k);
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}

