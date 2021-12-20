
//MST with MergeSort
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
#define SIZE 1000

typedef struct EdgeWithWeights
{
    int node1;
    int node2;
    int weight;
}edge;

int par[SIZE];
int sz[SIZE];
int n,e;


void init()
{
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        sz[i]=1;
    }
}

int findRoot(int u){
    if(par[u] == -1) return u;
    return findRoot(par[u]);
}

int formUnion(int a, int b){
    a = findRoot(a);
    b = findRoot(b);
    if(a == b) return 0;
    if(sz[a] > sz[b]){
        par[b] = a;
        sz[a] += sz[b];
    }else{
        par[a] = b;
        sz[b] += sz[a];
    }
    return 1;
}
void Kruskal(edge arr[]){
    init();
    mergeSort(arr,e);
    int i = 0;
    int e = n-1;
    int j=0,sum=0;
    while(i <= n-1){
        if(formUnion(arr[j].node1,arr[j].node2)!=0)
        {
           i++;
           sum+=arr[j].weight;
           printf("%d-----%d\n",arr[j].node1,arr[j].node2);
        }
        j++;
    }
    printf("Minimum cost: %d\n",sum);
}
void merger(edge left[],int leftsize,edge right[],int rightsize,edge arr[])
{
    int it1=0,it2=0,it3=0;
    while(it1<leftsize && it2<rightsize)
    {
        if(left[it1].weight<right[it2].weight)
        {
           arr[it3]=left[it1];
           it1++;
           it3++;
        }
        else
        {
           arr[it3]=right[it2];
           it2++;
           it3++;
        }
    }
    while(it2<rightsize)
    {
        arr[it3]=right[it2];
        it3++;
        it2++;
    }
    while(it1<leftsize)
    {
        arr[it3]=left[it1];
        it3++;
        it1++;
    }
}

int mergeSort(edge arr[],int n)
{
    if(n==1)return;
    edge left[n/2],right[n-n/2];
    int i,j;
    for(i=0,j=n/2; i<n/2,j<n; i++,j++)
    {
        left[i]=arr[i];
        right[i]=arr[j];
    }
    mergeSort(left,n/2);
    mergeSort(right,n-n/2);
    merger(left,n/2,right,n-n/2,arr);
}
int main()
{
    int i;
    printf("Enter Number of Edges and nodes: \n");
    scanf("%d%d",&e,&n);
    edge err[e];
    printf("Enter Node Number and Weights: \n");
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&err[i].node1,&err[i].node2,&err[i].weight);
    }
    Kruskal(err);
}

// With the bubble sort:

/*#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

typedef struct EdgeWithWeights
{
    int node1;
    int node2;
    int weight;
}edge;

int par[SIZE];
int sz[SIZE];
int n,e;


void init()
{
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        sz[i]=1;
    }
}

int findRoot(int u){
    if(par[u] == -1) return u;
    return findRoot(par[u]);
}

int formUnion(int a, int b){
    a = findRoot(a);
    b = findRoot(b);
    if(a == b) return 0;
    if(sz[a] > sz[b]){
        par[b] = a;
        sz[a] += sz[b];
    }else{
        par[a] = b;
        sz[b] += sz[a];
    }
    return 1;
}
void Kruskal(edge arr[]){
    init();
    Bublesort(arr,e);
    int i = 0;
    int e = n-1;
    int j=0,sum=0;
    while(i <= e-1){
        if(formUnion(arr[j].node1,arr[j].node2)!=0)
        {
           i++;
           sum+=arr[j].weight;
           printf("%d-----%d\n",arr[j].node1,arr[j].node2);
        }
        j++;
    }
    printf("Minimum cost: %d\n",sum);
}
void Bublesort(edge arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j].weight>arr[j+1].weight)
            {
                edge x=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=x;
            }
        }
    }
}
int main()
{
    int i;
    printf("Enter Number of Edges and nodes: \n");
    scanf("%d%d",&e,&n);
    edge err[e];
    printf("Enter Node Numbers and Weights: \n");
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&err[i].node1,&err[i].node2,&err[i].weight);
    }
    printf("\nTree Edges are:\n");
    Kruskal(err);
}
*/

