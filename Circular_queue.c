#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void display(int MAX);
int front=-1;
int rear=-1;
int CQueue[SIZE];

int isFull(int MAX){
        return (rear+1)%MAX==front;
}

int isEmpty(){
        return front==-1;
}

void enque(int value,int MAX){
        if(isFull(MAX)){
                printf("Queue is Full!!\n");
        }
        else if(front==-1 && rear==-1){
                front=0;
                rear=0;
                CQueue[rear]=value;
        }
        else{
                rear=(rear+1)%MAX;
                CQueue[rear]=value;
                display(MAX);
        }
}

void deque(int MAX){
        if(isEmpty()){
                printf("Queue is Empty!!\n");
        }
        else if(rear==front){
                printf("%d is Deleted!!",CQueue[front]);
                rear=-1;
                front=-1;
        }
        else{
                printf("%d is Deleted!!",CQueue[front]);
                front=(front+1)%MAX;
        }
}

void display(int MAX){
    if(isEmpty()){
        printf("Queue is empty!!\n");
    }
    else{
        printf("Queue elements are: ");
        int i = front;
        while(i != rear){
            printf("%d -> ", CQueue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", CQueue[rear]);
    }
}

void search(int value){
        if(isEmpty()){
                printf("Queue is Empty!!");
        }
        else{
                int pos=1;
                int i=front;
                while(i!=rear){
                        if(CQueue[i]==value){
                                printf("%d found at %d th position!",value,pos);
                                return;
                        }
                        else{
                                i=i+1;
                                pos=pos+1;
                        }
                }
                if(CQueue[rear]==value){
                        printf("%d found at %d th position!",value,pos);
                }
                else{
                        printf("%d not found!!",value);
                }
        }
}

void main(){
        int ch,value,MAX;
        printf("Enter the size of Queue:");
        scanf("%d",&MAX);
        do{
                printf("\n 1.Enque \n 2.Deque \n 3.Display \n 4.Search \n 5.exit \n Enter Your Choice: ");
                scanf("%d",&ch);
                switch(ch){
                        case 1:
                                printf("Enter the value to be Inserted: ");
                                scanf("%d",&value);
                                enque(value,MAX);
                                break;
                        case 2:
                                deque(MAX);
                                break;
                        case 3:
                                display(MAX);
                                break;
                        case 4:
                                printf("Enter the value to Search: ");
                                scanf("%d",&value);
                                search(value);
                                break;
                        case 5:
                                printf("Exiting the program..!!");
                                exit(0);
                        }
        }
        while(1);
}

