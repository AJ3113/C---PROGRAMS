#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;
void push(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    printf("Element pushed successfully\n");
}
void pop()
{
if(top==NULL)
{
    printf("Stack is empty\n");
    return;
}
struct node* temp=top;
top=top->next;
free(temp);
printf("Element popped successfully\n");
}
void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
       printf("Top element is: %d\n",top->data);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else{
        struct node* temp=top;
        printf("Stack elements:");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int choice,val;

    while(1)
    {
        printf("\n---- STACK USING LINKED LIST ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}