#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
char postfix[MAX];
int top = -1;

void push(int val){
    stack[++top] = val;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    return top == -1;
}

int evaluatePostfix(){
    int i;
    int op1, op2, result;

    for(i = 0; i < strlen(postfix); i++){
        if(postfix[i] == ' ')
            continue;

        if(isdigit(postfix[i])){
            int num = 0;
            while(i < strlen(postfix) && isdigit(postfix[i])){
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        }
        else{
            op2 = pop();
            op1 = pop();

            switch(postfix[i]){

                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main(){

    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    int result = evaluatePostfix();
    printf("%d", result);
    return 0;
}
