#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if(front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }

    printf("Element inserted\n");
}

void dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    printf("Queue elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);

    printf("\n");
}

int main()
{
    int choice, val;

    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
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
}