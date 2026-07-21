#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int isfull()
{
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
int empty()
{
    if(front==-1||front>rear)
    {
        return 1;

    }
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
    queue[++rear]=val;
    printf("Element enqueued successfully\n");
    }
}
void dequeue()
{
    if(empty())
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Element dequeued successfully\n");
        front++;
    }
    if(front>rear)
    {
        front=rear=-1;
    }
}
void display()
{
    if(empty())
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
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
                printf("Invalid Choice\n");
        }
    }
}
