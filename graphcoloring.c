#include<stdio.h>
#define MAX 100
int graph[MAX][MAX];int colour[MAX];
int n,m;
int issafe(int v,int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]==1 && colour[i]==c)
        {
            return 0;
        }
    }
    return 1;   
}
int graphcoloring(int v)
{
    if(v==n)
        return 1;
    for(int i=1;i<=m;i++)
    {
        if(issafe(v,i))
        {
            colour[v]=i;
            if(graphcoloring(v+1))
            {
                return 1;
            }
            colour[v]=0;//backtrack
        }
    }
    return 0;
}
int main()
{
    
   
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter number of colours: ");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    colour[i]=0;
    if(graphcoloring(0))
    {
        printf("Solution exists:\n");
        for(int i=0;i<n;i++)
        {
            printf("Vertex %d--->Colour %d\n",i,colour[i]);
        }
    }
    else
    {
        printf("No solution exists.\n");
    }
    return 0;
}