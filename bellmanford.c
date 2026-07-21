#include<stdio.h>
#define MAX 100
#define INF 9999
int main()
{
    int graph[MAX][MAX],dist[MAX],source,n;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            if(i!=j && graph[i][j]==0)
            {
                graph[i][j]=INF;
            }
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d",&source);
    /*printf("The adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
            
        }
        printf("\n");
    }*/
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
    }
    dist[source]=0;
    for(int k=1;k<=n-1;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]!=INF && dist[i]!=INF && dist[i]+graph[i][j]<dist[j])
                    dist[j]=dist[i]+graph[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]!=INF && dist[i]!=INF && dist[i]+graph[i][j]<dist[j])
            {
                printf("\nGraph contains a negative weight cycle.\n");
                return 0;
            }
        }
    }
    printf("\nShortest distance from source %d:\n",source);
    for(int i=0;i<n;i++)
    {
        printf("%d --->%d: %d\n",source,i,dist[i]);
    }
    return 0;
}