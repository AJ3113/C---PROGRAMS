#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int graph[MAX][MAX]; 
int visited[MAX];
int enqueue(int value)
{
    if(front==MAX-1 ||rear==MAX-1)
    {
        return -1;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=value;
    return 1;
}
int  dequeue()
{
    if(front==-1||front>rear)
    {
        return -1;
    }
    return queue[front++];
}
void bfs(int graph[MAX][MAX],int start,int n)
{
    enqueue(start);
    visited[start]=1;
    while(front<=rear)
    {
        int curr=dequeue();
        printf("%d ",curr);
        for(int i=0;i<n;i++)
        {
            if(graph[curr][i]==1 && visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
            }
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
    printf("BFS traversal starting from %d:",start);
    bfs(graph,start,n);
    return 0;
}