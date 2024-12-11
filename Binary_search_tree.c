#include<stdio.h>
#include<stdlib.h>

struct node{
        struct node *left;
        struct node *right;
        int data;
};
struct node* root=NULL;
//Insertion of Root Node
struct node* insert(struct node* root, int value)
{
        if (root == NULL)
        {
                struct node *newnode = malloc(sizeof(struct node));
                newnode->data = value;
                newnode->left = NULL;
                newnode->right = NULL;
                return newnode;
        }
        else if(value == root->data)
        {
                printf("Same data can't be stored\n");
        }
        else if (value > root->data) {
                root->right = insert(root->right, value);
        }
        else
        {
                root->left = insert(root->left, value);
        }
        return root;
}

// Inorder traversal
void inorderTraversal(struct node* root)
{
        if (root == NULL) return;
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root)
{
        if (root == NULL) return;
        printf("%d -> ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root)
{
        if (root == NULL) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d -> ", root->data);
}

struct node* search(struct node* root, int key)
{ 
        if (root == NULL)
        {
        printf("\nTree is Empty!\n"); 
        return NULL;
        }
        else if (root->data == key)
        {
        printf("\n%d is Found inside the Tree!",key);
        return root;
        }
        else if (root->data < key)
        {
        return search(root->right, key); 
        }
        else
        {
        return search(root->left, key);
        }
}

struct node* deleteNode(struct node* root, int key)
{
        if(root == NULL){
                printf("\nTree is Empty");
                return root;
        }
        if(key < root->data)
        root->left = deleteNode(root->left, key);
        else if (key > root->data)
        root->right = deleteNode(root->right, key);
        else
        {
        if(root->left == NULL)
        {
                struct node* temp = root->right;
                free(root);
                return temp;
        }
        else if (root->right == NULL)
        {
                struct node* temp = root->left;
                free(root);
                return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Display function using inorder traversal
void display(struct node* root)
{
        if (root == NULL)
        {
        printf("\nTree is empty\n");
        return;
        }
        inorderTraversal(root);
        printf("\n");
}

int main()
{
        struct node *root = NULL;
        int opt, value, searchv, key;
        do {
                printf("1) Insert Node\n2) Search\n3) Inorder Traversal\n4) Preorder Traversal\n5) Postorder Traversal\n6) Delete\n7) Display\n 8)exit\n");
                printf("Enter your choice : ");
                scanf("%d", &opt);
                switch(opt){
                        case 1:
                                printf("\nEnter a number: ");
                                scanf("%d", &value);
                                root = insert(root, value);
                                break;
                        case 2:
                                printf("\nEnter a number to search: ");
                                scanf("%d", &searchv);
                                search(root, searchv);
                                break;
                        case 3:
                                printf("\nInorder Traversal: ");
                                inorderTraversal(root);
                                printf("\n");
                                break;
                        case 4:
                                printf("\nPreorder Traversal: ");
                                preorderTraversal(root);
                                printf("\n");
                                break;
                        case 5:
                                printf("\nPostorder Traversal: ");
                                postorderTraversal(root);
                                printf("\n");
                                break;
                        case 6:
                                printf("\nEnter a number to delete: ");
                                scanf("%d", &key);
                                root = deleteNode(root, key);
                                break;
                        case 7:
                                printf("\nDisplay\n");
                                display(root);
                                break;
                        case 8:
                                printf("Exiting...\n");
                                break;
                        default:
                                printf("Invalid option!\n");
                }
        } while(opt != 8);
        return 0;
}
