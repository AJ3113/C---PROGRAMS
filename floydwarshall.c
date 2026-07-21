#include<stdio.h>
#define MAX 10
#define INF 9999
int main()
{
    int graph[MAX][MAX];
    int n;
    printf("Enter the number of vertices: ");
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
    //floyd warshall algorithm
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]!=INF && graph[k][j]!=INF && graph[i][k]+graph[k][j]<graph[i][j])
                {
                   graph[i][j]= graph[i][k]+graph[k][j];
                }
            }
        }
    }
    printf("Shortest distance matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==INF)
            printf("INF");
            else   
                printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}