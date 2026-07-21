#include<stdio.h>
#define MAX 100
#define INF 9999
int parent[MAX],graph[MAX][MAX];
int find(int parent[],int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}
void uni(int a,int b)
{
    parent[a]=b;
}
int main()
{
    int i,j,min,n,edges=0,totalcost=0;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        parent[i]=i;
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            if(i!=j && graph[i][j]==0)
            {
                graph[i][j]=INF;
            }
        }
    }
    printf("Edges into the minimum spanning tree: \n");
    while(edges<n-1)
    {
        min=INF;
        int u=-1,v=-1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
        {
            if(graph[i][j]<min)
            {
                min=graph[i][j];
                u=i;
                v=j;
            }
        }
    }
            int a=find(parent,u);
            int b=find(parent,v);
            if(a!=b)
            {
                printf("%d -> %d: %d\n",u,v,min);
                totalcost+=min;
                uni(a,b);
                edges++;
            }
            graph[u][v]=graph[v][u]=INF;
    }
    printf("\nTotal cost of minimum spanning tree: %d",totalcost);
    return 0;
}