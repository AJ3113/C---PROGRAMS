#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char item)
{
    if(top==MAX-1)
    printf("Stack is full\n");
    stack[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return stack[top--];
}
int precedence(char symbol)
{
 if(symbol=='^')
 return 3;
 else if(symbol=='*'||symbol=='/')
 return 2;
 else if(symbol=='+'||symbol=='-')
 return 1;
 else return -1;
}
void infixtopostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else if(infix[i]=='(')
        {
            push(infix[i++]);
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
             postfix[j++]=pop();
            }
            if(top!=-1 && stack[top]=='(')
            {
                pop();
            }
            i++;
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
            {
                postfix[j++]=pop();
            }
            push(infix[i++]);
        }
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main()
{
    char infix[MAX],postfix[MAX];
    printf("Enter the infix expression:");
    scanf(" %[^\n]", postfix);
    infixtopostfix(infix,postfix);
    printf("The postfix expression is:%s\n",postfix);
    return 0;
}