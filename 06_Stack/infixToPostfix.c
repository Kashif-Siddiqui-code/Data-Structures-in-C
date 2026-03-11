#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char ch){
    stack[++top] = ch;
}
char pop(){
    return stack[top--];
}
int isEmpty(){
    return top == -1;
}

int precedence(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void inToPost(){
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (symbol == ' ')
            continue;
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '('){
                postfix[j++] = next;
                postfix[j++] = ' ';
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)){
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(symbol);
            break;
        default: // operand
            postfix[j++] = symbol;
            postfix[j++] = ' ';
        }
    }
    while (!isEmpty()){
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }
    postfix[j - 1] = '\0'; // remove last extra space
}
int main()
{
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    inToPost();
    printf("%s", postfix);
    return 0;
}
