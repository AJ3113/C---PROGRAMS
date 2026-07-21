#include<stdio.h>
int binarysearch(int arr[],int x,int low,int high)
{
    if(low>high)
    return -1;
    int mid=(low+high)/2;
    if(arr[mid]==x)
    return mid;
    else if(arr[mid]>x)
    return binarysearch(arr,x,low,mid-1);
    else
    return binarysearch(arr,x,mid+1,high);
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
    int res=binarysearch(arr,x,0,n-1);
    if(res==-1)
    printf("Element not found in the array");
    else
    printf("Element found at position: %d",res+1);
    return 0;
}