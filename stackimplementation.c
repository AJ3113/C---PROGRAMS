#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isfull()
{
    if(top==MAX-1)
    return 1;
else return 0;
}
int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else return 0;
}
void push(int val)
{
    if(isfull())
    {
        printf("Stack is full\n");
    }
    else{
        stack[++top]=val;
        printf("Element pushed successfully\n");
    }
}
int pop()
{
    if(isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}
int peek()
{
    if(isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}
int main()
{
    int choice,val;
    while(1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be pushed:");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            val=pop();
            if(val!=-1)
            {
                printf("Popped element: %d\n",val);
            }
            break;
            case 3:
            val=peek();
            if(val!=-1)
            {
                printf("Top element: %d\n",val);
            }
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
