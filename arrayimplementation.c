#include <stdio.h>
#include<stdlib.h>
#define MAX 100
int insert(int arr[],int val,int pos,int *n)
{
    for(int i=*n;i>=pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=val;
      printf("Element inserted successfully\n");
     return ++(*n);
  
}
int delete(int arr[],int pos,int *n)
{
    for(int i=pos-1;i<*n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    printf("Element deleted successfully\n");
    return --(*n);
}
int search(int arr[],int val,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==val)
        return i+1;
    }
    return -1;
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() 
{
    int arr[MAX], n = 0;
    int choice, pos, val, i, found;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        }

    while(1)
    {
        printf("\n--- ARRAY MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted and the position:");
            scanf("%d %d",&val,&pos);
            if(pos<1||pos>n+1)
            printf("Invalid position\n");
            else
            n=insert(arr,val,pos,&n);
            break;
            case 2:
            printf("Enter the position to be deleted:");
            scanf("%d",&pos);
            if(pos<1||pos>n)
            printf("Invalid position\n");
            else
            n=delete(arr,pos,&n);
            break;
            case 3:
            printf("Enter the value to be searched:");
            scanf("%d",&val);
            found=search(arr,val,n);
            if(found==-1)
            printf("Element not found\n");
            else
            printf("Element found at position %d\n",found);
            break;
            case 4:
            printf("Array elements:");
            display(arr,n);
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}