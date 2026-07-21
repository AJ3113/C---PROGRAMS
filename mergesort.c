#include<stdio.h>
void merge(int arr[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=l;
    int b[r-l+1];
    while(i<=mid  && j<=r)
    {
        if(arr[i]<arr[j])
        {
            b[k++]=arr[i];
            i++;
        }
        else 
        {
            b[k++]=arr[j];
            j++;
        }
        if(i>mid)
        {
            while(j<=r)
            {
                b[k++]=arr[j++];
            }
        }
        if(j>r)
        {
            while(i<=mid)
            {
                b[k++]=arr[i++];
            }
        }
    }
    for(int i=l;i<=r;i++)
    {
        arr[i]=b[i];
    }
}
void mergesort(int arr[],int l,int r)
{
    int mid=(l+r)/2;
    if(l<r)
    {
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   
    mergesort(arr,0,n-1);
        printf("The sorted array is:\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    return 0;
}