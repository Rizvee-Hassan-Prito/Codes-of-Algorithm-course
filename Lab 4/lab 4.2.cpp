
#include<bits/stdc++.h>
#define N 100010
#define UNC 0
#define BL 1
#define RD 2
using namespace std;

long long int n,e,i,j,v,u;
vector<long long int>adj[N];
int col[N];
queue<long long int>que;

void Bipertite()
{
    col[1]=RD;
    que.push(1);
    while(que.size()!=0)
    {
        u=que.front();
        que.pop();
        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(col[v]==UNC)
            {
                if(col[u]==RD)col[v]=BL;
                else{col[v]=RD;}
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
    long long int sum=0,g=0,s=0;
    Bipertite();
    for(i=1;i<=n;i++)
    {
        if(col[i]==RD){g++;}
        if(col[i]==BL){s++;}
    }
    if(g>s)sum=g*200+s*500;
    else sum=g*500+s*200;
    printf("%lld",sum);
}
