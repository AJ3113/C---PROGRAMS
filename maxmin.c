#include<stdio.h>
struct Pair
{
    int max,min;
};
struct Pair findmaxmin(int arr[],int low,int high)
{
    struct Pair result,left,right;
    if(low==high)
    {
        result.max=arr[low];
        result.min=arr[low];
        return result;
    }
    if(high==low+1)
    {
        if(arr[high]>arr[low])
        {
            result.max=arr[high];
            result.min=arr[low];
        }
        else{
            result.max=arr[low];
            result.min=arr[high];
        }
        return result;
    }
    int mid=(high+low)/2;
    left=findmaxmin(arr,low,mid);
    right=findmaxmin(arr,mid+1,high);
    if(left.min<right.min)
    {
        result.min=left.min;
    }
    else{
        result.min=right.min;
    }
    if(left.max>right.max)
    {
        result.max=left.max;
    }
    else{
        result.max=right.max;
    }
    return result;
    
}
int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the number of elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Maximum and minimum in the array :\n");
    struct Pair res;
    res=findmaxmin(arr,0,n-1);
    printf("Maximum: %d\n",res.max);
    printf("Minimum: %d",res.min);
    return 0;
}
