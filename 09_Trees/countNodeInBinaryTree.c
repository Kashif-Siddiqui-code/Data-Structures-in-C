/*
Problem Statement:
Library Book Collection Tracker
Imagine you are building a system to manage the library book collection in a university. Each book in the library is represented by a unique Book ID, and these books are stored in a binary tree. As the number of books increases, it becomes essential to keep track of how many books are currently in the collection. To solve this, you need to develop a program that will count the total number of books (nodes) in the binary tree.
Write a program in Java that inserts a list of Book IDs into a binary tree and then counts the total number of nodes in the binary tree (i.e., the total number of books in the system). The program should take the number of Book IDs and the list of Book IDs as input, insert them into the tree, and return the total count of books stored in the tree.

Input Format
An integer n representing the number of books (nodes) in the binary tree.
n integers representing the unique Book IDs.

Output Format
An integer representing the total number of books (nodes) in the binary tree.
Sample Input
5
30 20 40 10 50

Sample Output
5
*/
#include <stdio.h>
#include <stdlib.h>

// Define Node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Counter Variable
int totalNodes = 0;

// Create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert nodes level-wise and count nodes
struct Node *insert(struct Node *root, int data) {
    // If tree is empty
    if (root == NULL) {
        totalNodes++;  // count first node
        return createNode(data);
    }
    struct Node *queue[1000];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        struct Node *temp = queue[++front];

        // Insert left child
        if (temp->left == NULL) {
            temp->left = createNode(data);
            totalNodes++;  // count node
            return root;
        } else {
            queue[++rear] = temp->left;
        }
        // Insert right child
        if (temp->right == NULL) {
            temp->right = createNode(data);
            totalNodes++;  // count node
            return root;
        } else {
            queue[++rear] = temp->right;
        }
    }
    return root;
}

// Main function
int main() {
    int n, x;
    struct Node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("%d\n", totalNodes);
    return 0;
}
