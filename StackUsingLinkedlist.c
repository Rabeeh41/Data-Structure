#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node* next;
};
struct node* top=NULL;
void Push(int value){
        struct node* Newnode=(struct node*)malloc(sizeof(struct node));
        if(!Newnode){
                 printf("Stack Overflow");
                 return;
        }
        Newnode->data=value;
        Newnode->next=top;
        top=Newnode;
        printf("%d pushed onto the stack\n",value);
}

void Pop(){
        if (top==NULL){
                printf("Stack UnderFlow");
                return;
        }
        struct node* temp=top;
        top=top->next;
        printf("%d poped from the stack \n",temp->data);
        free(temp);
}

void Display(){
        if(top==NULL){
                printf("Stack is Empty");
                return;
        }
        printf("Stack Elements:\n");
        struct node* temp=top;
        while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
        }
        printf("\n");
}

void Search(int value){
        struct node* temp= top;
        int position=1;
        while(temp != NULL){
                if(temp->data==value){
                        printf("%d found at poosition %d\n",value,position);
                        return;
                }
        temp=temp->next;
        position++;
        }
        printf("%d not Found in the Stack\n",value);
}

int main(){
        int choice,value;
        while(1){
                printf("\n choose an operation:\n 1.push\n 2.pop\n 3.Display\n 4.Search\n 5.Exit\n Enter your choice:\n");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter the value to push: ");
                                scanf("%d",&value);
                                Push(value);
                                break;
                        case 2:
                                Pop();
                                break;
                        case 3:
                                Display();
                                break;
                        case 4:
                                printf("Enter value to Search: ");
                                scanf("%d",&value);
                                Search(value);
                                break;
                        case 5:
                                printf("Exiting program!!");
                                exit(0);
                        default:
                                printf("Invalid choice.please try again: ");
                }
        }
        return 0;
}


