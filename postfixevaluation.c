#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int stack[100];
int top=-1;
void push(int val)
{
    if(top==MAX-1)
    {
        printf("stack is full\n");
    }
    else{
        stack[++top]=val;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}
int evaluatepostfix(char postfix[])
{
    int i=0;
    while(postfix[i]!='\0')
    {
        char ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else{
            int val2=pop();
            int val1=pop();
            switch(ch)
            {
                case '+':
                    push(val1+val2);
                    break;
                case '-':
                    push(val1-val2);
                    break;
                case '*':
                    push(val1*val2);
                    break;
                case '/':
                    push(val1/val2);
                    break;
            }
        }
        i++;
    }
    return pop();
}
int main()
{
    char postfix[MAX];
    printf("Enter a postfix expression:");
    scanf(" %[^\n]", postfix);
    int res=evaluatepostfix(postfix);
    printf("Result of the postfix expression is:%d\n",res);
    return 0;
}