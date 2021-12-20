#include <bits/stdc++.h>
#define N 1000
using namespace std;

struct Element{
    int node;
    int dt;

    Element(int _n, int _d){
        node = _n;
        dt = _d;
    }
    bool operator < (const Element &a) const&{
        return dt < a.dt;
    }
    bool operator > (const Element &a) const&{
        return dt > a.dt;
    }
};

priority_queue<Element, vector<Element>, greater<Element>> pq;
int dis[N];
bool vis[N];
int n, e, weight, u, v;
vector<int> adj[N],adjw[N];
int path[N];

void dijkstra(int src){

    dis[src] = 0;
    for(int i=1; i<=e; i++){
        if(i!=src){
            dis[i] = 999999;
        }
        vis[src] = false;
    }

    pq.push(Element(src, 1));
    int u, v, w;

    while(!pq.empty()){
        u = pq.top().node;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i];
            w = adjw[u][i];
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u] + w;
                path[v]=u;
                pq.push(Element(v, dis[v]));
            }
        }
    }
}
int main()
{
    printf("\nHere, Node number for a=1,b=2,c=3,d=4,e=5,f=6,...\n");
    printf("\nEnter total node and edges:\n");
    scanf("%d%d",&n,&e);
    int u,v,w;
    printf("Enter edges and weights:\n");
    for(int i=0;i<e;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back(v);
        path[v]=u;
        adjw[u].push_back(w);
    }
    dijkstra(1);
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("Shortest path from node 1 to node %d:%d\n",i,dis[i]);
    }
    printf("\nFollowing path is the shortest path with the lowest cost:\n");
    int stp;
    int parent=n;
    printf("%d",n);
    while(stp!=1)
    {
        parent=path[parent];
        stp=parent;
        printf("<-%d",stp);
    }
    printf("\n");
}
