#include<stdio.h>
void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("The sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
     printf("\n");
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
   
    insertionsort(arr,n);
    return 0;
}
