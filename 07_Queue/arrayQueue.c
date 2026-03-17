#include <stdio.h>
#include <string.h>

#define MAX_NAME 100

int MAX;                     // capacity of queue
int front = -1;
int rear = -1;

char queue[100][MAX_NAME];  // queue to store customer names

void enqueue(char name[]) {
    if(rear == MAX - 1) {
        printf("Queue is full. Cannot add %s\n", name);
        return;
    }
    if(front == -1)
        front = 0;
    rear++;
    strcpy(queue[rear], name);
}

void dequeue() {

    if(front == -1 || front > rear) {
        printf("Served Customer: Queue is empty. No customer to serve.\n");
        return;
    }
    printf("Served Customer: %s\n", queue[front]);
    front++;
    
    if(front > rear) {   // queue became empty
        front = -1;
        rear = -1;
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

int main() {
    int operations;
    char command[20];
    char name[MAX_NAME];
    scanf("%d", &MAX);           // queue capacity
    scanf("%d", &operations);    // number of operations

    for(int i = 0; i < operations; i++) {
        scanf("%s", command);
        if(strcmp(command, "ENQUEUE") == 0) {
            scanf("%s", name);
            enqueue(name);
        }
        else if(strcmp(command, "DEQUEUE") == 0) {
            dequeue();
        }
        else if(strcmp(command, "DISPLAY") == 0) {
            display();
        }
    }
    return 0;
}
