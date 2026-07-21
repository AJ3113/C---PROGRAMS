#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
    while(start <= ub && arr[start]<=pivot)
    {
        start++;
    }
    while(arr[end]>pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(&arr[start],&arr[end]);
    }
}
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int pivot=partition(arr,lb,ub);
        quicksort(arr,lb,pivot-1);
        quicksort(arr,pivot+1,ub);
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
   
    quicksort(arr,0,n-1);
        printf("The sorted array is:\n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    return 0;
}