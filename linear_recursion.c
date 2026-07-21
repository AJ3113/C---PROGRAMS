//Recursive approach
#include<stdio.h>
int linearsearch(int arr[],int x,int n)
{
    if(n==0)
    return -1;
if(arr[n-1]==x)
return n-1;
return linearsearch(arr,x,n-1);
}
int main()
{
    int n,x;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched");
    scanf("%d",&x);
    int res=linearsearch(arr,x,n);
    if(res==-1)
    printf("Element not found in the array");
    else
    printf("Element found at position: %d",res+1);
    return 0;
}