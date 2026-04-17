/*
Problem Statement:
Organizing a Library Collection
A library is implementing a system to organize books based on their unique book IDs. The system should use a Binary Search Tree (BST) to manage the collection. 
Each book has a unique ID, and the library needs to insert new books into the system while maintaining the BST property. Your task is to implement the 
insertion of a new book ID into the existing BST.
Given the root node of a Binary Search Tree (BST) representing books in the library, and a value representing the book's unique ID, return the root node of the BST 
after inserting the new book ID. It is guaranteed that the new book ID does not exist in the original BST.

Implement a Binary Search Tree where each node represents a book's unique ID.
Ensure that after inserting a new book ID, the BST properties are maintained:
For any node N, all values in the left subtree of N must be smaller than N.val, and all values in the right subtree of N must be larger than N.val.
Return the root node of the updated BST.

Input Format
First, enter the number of books (n) already in the system (number of nodes in the BST).
Next, enter the unique IDs of the books (n integers) which will form the initial BST.

Output Format:
After the insertion, print the In-Order Traversal of the updated BST, which should display the book IDs in ascending order.

Sample Input
5
50 30 70 20 40

Sample Output
20 30 40 50 70
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int value){
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
// insert into BST
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
// print in in-order
void inorder(struct node *root){
  if(root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}
int main(){
  int n;
  scanf("%d", &n);
  int val;
  scanf("%d", &val);
  struct node *root = createNode(val);
  for(int i=1; i<n; i++){
    scanf("%d", &val);
    insert(root, val);
  }
  inorder(root);
  return 0;
}

