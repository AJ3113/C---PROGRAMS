#include<stdio.h>
#define MAX 10
#define INF 9999
int main()
{
    int graph[MAX][MAX];
    int visited[MAX]={0};int i,j,n,min,x,y;
    int totalcost=0;
    int edges=0;
     printf("Enter number of vertices: ");
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
     visited[0]=1;
     printf("Edges in the minimum spanning tree:\n");
     while(edges<n-1)
     {
        min=INF;
        for(i=0;i<n;i++)
        {
            if(visited[i]){
            for(j=0;j<n;j++)
            {
                if(!visited[j] && graph[i][j]<min)
                {
                    min=graph[i][j];
                    x=i;
                    y=j;
                }
            }
        }
    }
        printf("%d -> %d: %d\n",x,y,min);
        visited[y]=1;
        totalcost+=min;
        edges++;
     }
     printf("\nTotal cost of minimum spanning tree: %d",totalcost);
     return 0;
}