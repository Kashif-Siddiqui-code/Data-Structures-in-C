#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        top = top + 1;
        stack[top] = value;
        // stack[++top] = value;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top = top - 1;
    // top--;
}
// peek
void peek() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
}

void isEmpty() {
    if (top == -1)
        printf("true\n");
    else
        printf("false\n");
}

void size() {
    printf("%d\n", top + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    char command[20];
    int value;
    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "Push") == 0) {
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(command, "Pop") == 0) {
            pop();
        }
        else if (strcmp(command, "Top") == 0) {
            topElement();
        }
        else if (strcmp(command, "IsEmpty") == 0) {
            isEmpty();
        }
        else if (strcmp(command, "Size") == 0) {
            size();
        }
    }
    return 0;
}
