/*
Problem Statement:
Efficient Book Search in a Digital Library
Imagine you are developing a Digital Library Management System for a university that holds a large collection of books, each identified by a unique Book ID. 
The library system needs to efficiently store, manage, and retrieve information about these books. To ensure quick search operations, the Book IDs are stored in 
a Binary Search Tree (BST). Every time a student or librarian enters a Book ID, the system searches for the book in the BST. If the Book ID exists, the system 
returns information about that book along with details of related books (those with Book IDs close to the searched ID). If the Book ID does not exist in the 
library's catalog, the system should notify the user that the book is unavailable.

In this library system:
Each book is assigned a unique Book ID based on the year of publication, genre code, and a unique serial number.
The system needs to handle searches efficiently as the library grows, with thousands of books being stored.
When a librarian or student searches for a book, they want to know if the book is available, along with recommendations for other similar books (based on Book ID
proximity). For example, if a student searches for a book with Book ID 1040, and the book is found, the system should return this book's details. 
It should also suggest other books with similar IDs, i.e., books in the same subtree.

Input Format
First, enter the number of books (n) available in the library system.
Then, enter n unique book IDs (these are used to construct the BST).
After that, enter the Book ID (val) you want to search for.

Output Format
If the book is found, display the message "Book found!" and print the In-Order Traversal of the subtree rooted at the found node.
If the book is not found, display the message "Book not found."

Sample Input 1
6
50 30 70 20 40 60
30

Sample Output 1
Book found! Subtree rooted at 30:
20 30 40
*/


#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
// Create Node
struct node *createNode(int value){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert into BST
struct node *insert(struct node *root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}
// Inorder Traversal
void inorder(struct node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Search in BST
struct node* search(struct node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    struct node *root = NULL;
    int val;

    // Read n book IDs
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Read search value
    int searchVal;
    scanf("%d", &searchVal);

    // Search
    struct node *foundNode = search(root, searchVal);

    if(foundNode != NULL){
        printf("Book found! Subtree rooted at %d:\n", searchVal);
        inorder(foundNode);
    } else {
        printf("Book not found\n");
    }
    return 0;
}
