#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* link;
};
struct node* Head=NULL;

void InsertBEG(int value){
        struct node* Newnode=(struct node*)malloc(sizeof(struct node));
        Newnode->data=value;
        if(Head==NULL){
                Head=Newnode;
                Head->link=NULL;
                }
        else{
                Newnode->link=Head;
                Head=Newnode;
        }
        printf("%d is Inserted at the begnning\n",value);
}


void InsertEND(int value){
        struct node* Newnode=(struct node*)malloc(sizeof(struct node));
        Newnode->data=value;
        struct node* temp=Head;
        Newnode->link=NULL;
        if(Head==NULL){
                Head=Newnode;
        }
        else{
                struct node* temp=Head;
                while(temp->link != NULL){
                        temp=temp->link;
                }
                temp->link=Newnode;
        }
        printf("%d is inserted into list!",value);
}

void InsertPOS(int value,int position){ 
        struct node* temp=Head;
        int count=1;
        if(position==1){
                        InsertBEG(value);
                }
        else{
                while(temp->link != NULL && count<position-1){
                        temp=temp->link;
                        count++;
                }
                if(temp->link==NULL){
                        InsertEND(value);
                }
                else{
                        struct node* Newnode=(struct node*)malloc(sizeof(struct node));
                        Newnode->data=value;
                        Newnode->link=temp->link;
                        temp->link=Newnode;
                        printf("%d is inserted into list!",value);
                }
        }
}


void DisplayList(){
        struct node* temp=Head;
        if(Head==NULL){
                printf("List is Empty!!");
                }
        else{
                printf("Elements in List is:\n");
                while(temp!=NULL){
                        printf("%d->",temp->data);
                        temp=temp->link;
                        }
                }
        }

void Del_Beg(){
        if(Head==NULL){
                printf("List is Empty!! ");
        }
        else{
                struct node* temp=Head;
                Head=Head->link;
                printf("%d is deleted from begnning of list!",temp->data);
                free(temp);
        }
}

void Del_End(){
        if(Head==NULL){
                printf("List is Empty!");
        }
        else if(Head->link==NULL){
                Del_Beg();
        }
        else{
                struct node* temp=Head;
                while(temp->link->link != NULL){
                        temp=temp->link;
                }
                struct node* last=temp;
                temp=temp->link;
                printf("%d is deleted from end of the list",temp->data);
                free(temp);
                last->link=NULL;
        }
}

void Del_Pos(int pos){
        if(Head==NULL){
                printf("List is Empty!");
        }
        else if(pos==1){
                Del_Beg();
        }
        int count=1;
        struct node* temp=Head;
        while(temp->link != NULL && count<pos-1){
                temp=temp->link;
        }
        if(temp->link==NULL){
                Del_End();
        }
        else{
                struct node* del=temp->link;
                temp->link=del->link;
                printf("%d is deleted from list",del->data);
                free(del);
        }
}

void main(){
        int value,position,choice,pos;
        while(1){
                printf("\n Choose an operation:\n 1.Isert at begning\n 2.Insert at the end\n 3. insert at random position\n 4.Deletion at Begnning\n 5.deletion at end\n 6.deletion at any position\n 7.Display\n 8.exit\n Enter you choice: \n");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                printf("Enter the value to push:");
                                scanf("%d",&value);
                                InsertBEG(value);
                                break;
                        case 2:
                                printf("Enter the value to push:");
                                scanf("%d",&value);
                                InsertEND(value);
                                break;
                        case 3:
                                printf("Enter the position to insert: ");
                                scanf("%d",&position);
                                printf("Enter the value to be inserted: ");
                                scanf("%d",&value);
                                InsertPOS(value,position);
                                break;
                        case 4:
                                Del_Beg();
                                break;
                        case 5:
                                Del_End();
                                break;
                        case 6:
                                printf("Enter the position to delete");
                                scanf("%d",&pos);
                                Del_Pos(pos);
                                break;
                        case 7:
                                DisplayList();
                                break;
                        case 8:
                                exit(0);
                        }
                }
        }


