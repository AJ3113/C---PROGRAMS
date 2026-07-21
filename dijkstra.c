#include<stdio.h>
#define MAX 100
#define INF 9999
int main()
{
    int graph[MAX][MAX],dist[MAX],visited[MAX]={0};
    int start,n,min,u;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",graph[i][j]);
            if(i!=j && graph[i][j]==0)
            graph[i][j]=INF;
        }
    }
    printf("Enter the starting vertex:\n");
    scanf("%d",&start);
    for(int i=0;i<n;i++)
    {
        dist[i]=graph[start][i];
    }
    dist[start]=0;
    visited[start]=1;
    for(int i=1;i<n;i++)
    {
        min=INF;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&dist[u]+graph[u][j]<dist[j])
            {
                dist[j]=dist[u]+graph[u][j];
            }
        }

    }
    printf("The shortest distances from vertex %d are:\n",start);
    for(int i=0;i<n;i++)
    {
        printf("Vertex %d: %d\n",i,dist[i]);
    }
    return 0;
}