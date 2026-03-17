#include <stdio.h>

int main() {
    int n;

    // read number of elements
    scanf("%d", &n);

    int queue[n];
    int stack[n];
    int top = -1;

    // input queue elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // push all queue elements into stack
    for(int i = 0; i < n; i++) {
        top++;
        stack[top] = queue[i];
    }

    // pop elements from stack and print
    while(top != -1) {
        printf("%d ", stack[top]);
        top--;
    }

    return 0;
}
