#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;
        printf("Deleted element = %d\n", front->data);
        front = front->next;
        free(temp);

        if(front == NULL)
            rear = NULL;
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;
    printf("Queue elements are:\n");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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