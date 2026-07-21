#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insertatfront(int val)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=val;
    newnode->next=head;
    head=newnode;
    printf("Element inserted at front successfully\n");
}
void insertatend(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        struct node* current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=newnode;
        printf("Element inserted at end successfully\n");
    }
}
void deleteatfront()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else{
        struct node* temp=head;
        head=head->next;
        printf("Element deleted at front successfully\n");
        free (temp);
    }
}
void deleteatend()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("Element deleted at end successfully\n");
    }
    else{
        struct node* current=head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        free(current->next);
        current->next=NULL;
        printf("Element deleted at end successfully\n");
    }
}
void  display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else{
        struct node* current=head;
        printf("List elements:\n");
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current=current->next;
        }
        printf("\n");
    }
}
int main() {
    int choice;
    while(1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert Front  2. Insert End  3. Delete Front  4. Delete End  5. Display  6. Exit\n");
        printf("Enter choice: "); scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int val;
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertatfront(val);
                break;
            }
            case 2: {
                int val;
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertatend(val);
                break;
            }
            case 3: deleteatfront(); break;
            case 4: deleteatend(); break;
            case 5: display(); break; case 6: exit(0);
        }
    }
}
