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

int n,e, hasCycle=0;
vector <int>adj[N];
int col[N];
void dfs(int node)
{
    int i;
   col[node]=GREY;
   for(i=0;i<adj[node].size();i++)
   {
       if(hasCycle==1){return;}
       int v=adj[node][i];
       if(col[v]==WHITE)
       {
           dfs(v);
       }
       else if(col[v]==GREY)
       {
           printf("no");
           hasCycle=1;
           return;
       }
   }
   col[node]=BLACK;
}
int main() {
    int i,u,v;
    scanf("%d%d",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }
    for(i=1;i<=n;i++)
    {
        col[i]=WHITE;
    }
    for(i=1;i<=n;i++)
    {
        if(col[i]==WHITE)
        {
            dfs(i);
        }
    }
    if(hasCycle==1){return 0;}
    printf("yes");
}
