#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ticket[50];
    struct node *next;
};

struct node *front = NULL; 
struct node* rear = NULL;

void enqueue(char ticket[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->ticket, ticket);
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } 
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("Processed Ticket: %s\n", front->ticket);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = front;
    printf("Current Queue: ");
    while (temp != NULL) {
        printf("%s ", temp->ticket);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int operations;
    char command[20];
    char ticket[50];
    scanf("%d", &operations);
    for (int i = 0; i < operations; i++) {
        scanf("%s", command);
        if (strcmp(command, "ENQUEUE") == 0) {
            scanf("%s", ticket);
            enqueue(ticket);
        }
        else if (strcmp(command, "DEQUEUE") == 0) {
            dequeue();
        }
        else if (strcmp(command, "DISPLAY") == 0) {
            display();
        }
        else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}
