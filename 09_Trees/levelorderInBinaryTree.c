/*Organizing a Cricket Tournament
In a cricket tournament, each team is ranked based on their performance. The teams need to be organized in a binary tree structure to quickly manage and track matchups. The binary tree represents the tournament bracket, where each node corresponds to a team, and the tree helps efficiently find opponents and record match results.
As the organizer, you need to insert new teams into this binary tree structure based on their registration order. Your task is to create a system that inserts teams into the binary tree and then displays the teams in a level-order (top-to-bottom) manner, so you can view the bracket.
Input Format
First line contains the number of teams to be inserted.
Next line contains the team rankings (as integers) to be inserted into the binary tree in sequence.
Output Format
After all teams are inserted, display the team rankings in level-order traversal.
Sample Input
6
8 3 10 1 6 14
Sample Output
8 3 10 1 6 14*/



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int val;
    scanf("%d", &val);

    // Create root
    struct node* root = createNode(val);

    // Simple queue using array
    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    // Insert remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        struct node* newNode = createNode(val);

        struct node* temp = queue[front];

        // Insert left
        if (temp->left == NULL) {
            temp->left = newNode;
            queue[rear++] = newNode;
        }
        // Insert right
        else if (temp->right == NULL) {
            temp->right = newNode;
            queue[rear++] = newNode;
            front++; // move to next node
        }
    }

    // Level Order Traversal
    front = 0;
    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);
    }

    return 0;
}
