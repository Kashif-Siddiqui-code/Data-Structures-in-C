#include <stdio.h>
#include <stdlib.h>

/*
Write a program that inserts a new task (represented by a unique task ID) at a specific position in the task list. 
After the insertion, print the updated list of task IDs. If the entered position value is out the range, 
print the message as “Position out of range”.
*/
// Insert at specific position
// Node structure
struct node{
    int data;
    struct node *next;
};

// Insert at End
void insert_at_end(struct node **head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Insert at Specific Position
void insert_at_pos(struct node **head, int data, int pos){
    
    // position always greater than zero
    if(pos<=0){
        printf("Positin must be greater than zero");
        return;
    }
            
    // create new node
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    // store data
    temp->data = data;
    temp->next = NULL;

    // If pos == 1: Insert at beginning
    if(pos == 1){
        temp->next = *head;
        *head = temp;
        return;
    }
    
    struct node *ptr = *head;
    // Traverse to (pos - 1)
    for(int i = 1; i < pos - 1; i++){
        if(ptr == NULL){
            printf("Position out of range");
            return;
        }
        ptr = ptr->next;
    }
    // Position validation
    if(ptr == NULL){
        printf("Position out of range");
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

// Print List
void print_list(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int N, P, M, id;
    struct node *head = NULL;
    // Input N
    scanf("%d", &N);
    // Input list
    for(int i = 0; i < N; i++){
        scanf("%d", &id);
        insert_at_end(&head, id);
    }
    // Input Position
    scanf("%d", &P);
    // Input New Task ID
    scanf("%d", &M);
    // Insert
    insert_at_pos(&head, M, P);
    // Print Updated List
    print_list(head);
    return 0;
}
