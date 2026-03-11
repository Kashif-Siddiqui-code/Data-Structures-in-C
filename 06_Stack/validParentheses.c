#include <stdio.h>
#include <string.h>
#define MAX 1000
int main(){
    char str[MAX];
    char stack[MAX];
    int top = -1;
    scanf("%s", str); // [ { ( } ]
    for (int i = 0; i < strlen(str); i++){
        char ch = str[i];
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;      // push function code
        }
        // If closing bracket
        else
        { if (top == -1)
            {
                printf("false");
                return 0;
            }
            char topElement = stack[top];
            if ((ch == ')' && topElement == '(') ||
                (ch == '}' && topElement == '{') ||
                (ch == ']' && topElement == '['))
            {
                top--; // pop
            }
            else{
                printf("false");
                return 0;
            }
        }
    }
    if (top == -1)
        printf("true");
    else
        printf("false");
    return 0;
}
