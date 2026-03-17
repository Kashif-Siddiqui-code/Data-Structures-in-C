#include <stdio.h>
#include <string.h>

#define MAX 100

// Queue 1
int q1[MAX];
int front1 = -1, rear1 = -1;

// Queue 2
int q2[MAX];
int front2 = -1, rear2 = -1;

// QUEUE 1
void enqueue1(int value){
    if(rear1 == MAX - 1){
        printf("Queue1 Overflow\n");
        return;
    }
    if(front1 == -1){
        front1 = 0;
    }
    rear1++;
    q1[rear1] = value;
}

int dequeue1(){
    if(front1 == -1 || front1 > rear1){
        return -1;
    }
    return q1[front1++];
}

int isEmpty1(){
    return (front1 == -1 || front1 > rear1);
}

int getFront1(){
    return q1[front1];
}

// QUEUE 2 FUNCTIONS
void enqueue2(int value){
    if(rear2 == MAX - 1){
        printf("Queue2 Overflow\n");
        return;
    }
    if(front2 == -1){
        front2 = 0;
    }
    rear2++;
    q2[rear2] = value;
}
int dequeue2(){
    if(front2 == -1 || front2 > rear2){
        return -1;
    }
    return q2[front2++];
}
int isEmpty2(){
    return (front2 == -1 || front2 > rear2);
}
// STACK OPERATIONS
void push(int x){
    enqueue2(x);            // Insert new element into q2
    
    while(!isEmpty1()){     // Move all elements from q1 → q2
        enqueue2(dequeue1());
    }
    
    front1 = 0;         // Step 3: Copy q2 → q1
    rear1 = -1;
    for(int i = front2; i <= rear2; i++){
        q1[++rear1] = q2[i];
    }
    // Step 4: Reset q2
    front2 = -1;
    rear2 = -1;
    printf("Pushed: %d\n", x);
}

void pop(){
    if(isEmpty1()){
        printf("Stack Underflow\n");
        return;
    }
    int val = dequeue1();
    printf("Popped: %d\n", val);
}

void top(){
    if(isEmpty1()){
        printf("Stack is empty\n");
        return;
    }
    printf("Top version: %d\n", getFront1());
}

void empty(){
    if(isEmpty1())
        printf("Is stack empty: true\n");
    else
        printf("Is stack empty: false\n");
}
int main(){
    int n;
    scanf("%d", &n);
    char op[10];
    int value;
    for(int i = 0; i < n; i++){
        scanf("%s", op);
        if(strcmp(op, "push") == 0){
            scanf("%d", &value);
            push(value);
        }
        else if(strcmp(op, "pop") == 0){
            pop();
        }
        else if(strcmp(op, "top") == 0){
            top();
        }
        else if(strcmp(op, "empty") == 0){
            empty();
        }
    }
    return 0;
}
