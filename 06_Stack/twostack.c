#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int val){
    if(top1 + 1 == top2){
        printf("Stack Overflow\n");
        return;
    }
    top1++;
    arr[top1] = val;
}

void push2(int val){
    if(top1 + 1 == top2){
        printf("Stack Overflow\n");
        return;
    }
    top2--;
    arr[top2] = val;
}

void pop1(){
    if(top1 == -1){
        printf("Stack1 Underflow\n");
        return;
    }
    printf("Popped from Stack1: %d\n", arr[top1]);
    top1--;
}

void pop2(){
    if(top2 == MAX){
        printf("Stack2 Underflow\n");
        return;
    }
    printf("Popped from Stack2: %d\n", arr[top2]);
    top2++;
}

void display(){
    int i;
    printf("\nArray Elements:\n");
    for(i = 0; i < MAX; i++)
        printf("%d ",arr[i]);

    printf("\n");
}

int main()
{
    push1(10);
    push1(20);
    push1(30);

    push2(90);
    push2(80);
    push2(70);

    display();

    pop1();
    pop2();

    display();

    return 0;
}
// Portal Problem
// #include <stdio.h>

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int arr[n];

//     int top1 = -1;
//     int top2 = n;

//     int command;

//     while (1)
//     {
//         scanf("%d", &command);
//         if (command == -1)
//             break;

//         if (command == 1){   // Push1
//             int x;
//             scanf("%d", &x);
//             if (top1 + 1 != top2){
//                 top1++;
//                 arr[top1] = x;
//             }
//         }
//         else if (command == 2){ // push2
//             int x;
//             scanf("%d", &x);

//             if (top1 + 1 != top2){
//                 top2--;
//                 arr[top2] = x;
//             }
//         }
//         else if (command == 3){ // pop1
//             if (top1 != -1){
//                 printf("%d\n", arr[top1]);
//                 top1--;
//             }
//         }

//         else if (command == 4){ // pop2
//             if (top2 != n){         
//                 printf("%d\n", arr[top2]);
//                 top2++;
//             }
//         }
//     }
//     return 0;
// }
