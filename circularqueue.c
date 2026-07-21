#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
int isfull()
{
    if((rear+1)%MAX==front)
    return 1;
    else return 0;
}
int isempty()
{
    if(front==-1)
    return 1;
else return 0;  
}
void enqueue(int val)
{
    if(isfull())
    {
        printf("Queue is full\n");
    }
    else{
        if(front==-1)
        front=0;
    rear=(rear+1)%MAX;
    queue[rear]=val;
}
}
void dequeue()
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Element dequeued successfully\n");
        if(front==rear)
        {
            rear=front=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}
void display()
{
    if(isempty())
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements:\n");
        int i=front;
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d\n",queue[rear]);
    }
}
int main()
{
    int choice,val;
    while(1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
            printf("Enter the value to be enqueued:");
            scanf("%d",&val);
            enqueue(val);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}