#include<bits/stdc++.h>
#define N 100005
using namespace std;

long long int n,e,i,j,v,u;
vector<long long int>adj[N];
int dis[N];
queue<long long int>que;

void BFS(int src)
{
    for(i=1;i<=n;i++)dis[i]=-1;
    dis[src]=0;
    que.push(src);
    while(que.size()!=0)
    {
        u=que.front();
        que.pop();
        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(dis[v]==-1)
            {
                dis[v]=1+dis[u];
                que.push(v);
            }
        }
    }
}

int main()
{
    scanf("%lld%lld",&n,&e);
    for(i=0;i<e;i++)
    {
        scanf("%lld%lld",&u,&v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    long long int maxm=0;
    BFS(1);
    for(i=1;i<=n;i++)
    {
        if(maxm<dis[i]){maxm=dis[i];}
    }
    printf("%lld",maxm);
}
