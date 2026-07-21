#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
struct node* createNode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
    {
        root=createNode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}
int countnodes(struct node* root)
{
    if(root==NULL)
    return 0;
    return 1+countnodes(root->left)+countnodes(root->right);
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int findmin(struct node* root)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    while(root->left!=NULL)
    root=root->left;
    return root->data;
}
int findmax(struct node* root)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int main()
{
    int choice,val;
    while(1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Count Nodes\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Find Minimum\n");
        printf("7. Find Maximum\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d", &val);
                root=insert(root,val);
                break;
                case 2:
                 printf("Total nodes: %d\n", countnodes(root));
                break;
                case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
                case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
                case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
                
                case 6:
                printf("Minimum element: %d\n", findmin(root));
                break;

                case 7:
                printf("Maximum element: %d\n", findmax(root));
                break;
                case 8:
                exit(0);
                default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}