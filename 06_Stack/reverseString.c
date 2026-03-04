#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char ch){
    if(top == MAX - 1){
        return;
    }
    top = top + 1;
    stack[top] = ch;
}

char pop(){
    if(top == -1){
        return '\0';
    }
    char ch = stack[top];
    top = top - 1;
    return ch;
}

int main(){
    char str[MAX];
    int len;

    fgets(str, MAX, stdin);
    len = strlen(str);

    // remove newline character
    if(str[len - 1] == '\n'){
        str[len - 1] = '\0';
        len--;
    }

    // push characters into stack
    for(int i = 0; i < len; i++){
        push(str[i]);
    }

    // pop characters back to string
    for(int i = 0; i < len; i++){
        str[i] = pop();   // FIXED HERE
    }
    printf("%s", str);
    return 0;
}
