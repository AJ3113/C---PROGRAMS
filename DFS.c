#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void dfs(int graph[MAX][MAX], int start, int n)
{
    visited[start]=1;
    printf("%d ",start);
    for(int i=0;i<n;i++)
    {
        if(graph[start][i]==1 && visited[i]==0)
        {
            dfs(graph,i,n);
        }
    }
    
}
int main()
{
     int n;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("The adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    int start;
    printf("Enter the starting vertex:\n");
    scanf("%d",&start);
    printf("DFS traversal starting from %d:",start);
    dfs(graph,start,n);
    return 0;
}