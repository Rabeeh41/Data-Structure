#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* createNode(int data) {
    struct node* tempnode = (struct node*)malloc(sizeof(struct node));
    tempnode->data = data;
    tempnode->next = NULL;
    tempnode->prev = NULL;
    return tempnode;
}

void insertAtBeg(int val) {
    struct node* newNode = createNode(val);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtAny(int data, int pos) {
    if (pos < 1) {
        printf("Position cannot be negative or zero .\n");
        return;
    }
    if (pos == 1) {
        insertAtBeg(data);
        return;
    }
    struct node* newNode = createNode(data);
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position cannot be greater than the length of the list.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d is deleted\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("%d is deleted\n", temp->data);
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;  // If there's only one node
    }
    free(temp);
}

void deleteAtAny(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Position cannot be zero or negative.\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeg();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Enter valid position. Position is greater than the length of the list.\n");
        return;
    }
    if(temp->next ==NULL){
        deleteAtEnd();
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    printf("%d is deleted\n", temp->data);
    free(temp);
}

void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, input, pos;
    do {
        printf("\nSelect the option: \n");
        printf("1. Insert at beginning:\n");
        printf("2. Insert at end:\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specific position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &input);
                insertAtBeg(input);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &input);
                insertAtEnd(input);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &input);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertAtAny(input, pos);
                break;
            case 4:
                deleteAtBeg();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtAny(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (ch != 8);
    return 0;
}
