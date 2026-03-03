#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char book[101];
    struct node *next;
};

struct node *top = NULL;
int count = 0;

void push(char name[]) {

    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    strcpy(newNode->book, name);
    newNode->next = top;
    top = newNode;
    count++;
}

void pop() {

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    top = top->next;
    free(temp);
    count--;
}

void peek() {

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%s\n", top->book);
}

void isEmpty() {

    if (top == NULL)
        printf("true\n");
    else
        printf("false\n");
}

void size() {

    printf("%d\n", count);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // remove leftover newline
    char line[200];

    for (int i = 0; i < N; i++) {
        fgets(line, sizeof(line), stdin);
        // remove newline
        line[strcspn(line, "\n")] = 0;
        // PUSH
        if (strncmp(line, "Push ", 5) == 0) {

            push(line + 5);
        }
        // POP
        else if (strcmp(line, "Pop") == 0) {

            pop();
        }
        // TOP
        else if (strcmp(line, "Top") == 0) {

            peek();
        }
        // ISEMPTY
        else if (strcmp(line, "IsEmpty") == 0) {

            isEmpty();
        }
        // SIZE
        else if (strcmp(line, "Size") == 0) {

            size();
        }
    }
    return 0;
}
