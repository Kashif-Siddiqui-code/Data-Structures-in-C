/*
Problem Description:
Company Employee Management System
In a company employee management system, employee IDs are stored in a Binary Search Tree (BST) to allow fast searching and organized storage.
Each node in the BST represents an employee ID.
Employee IDs are inserted into the BST one by one.
The preorder traversal of the BST is used to back up the employee records, as it visits the root before its subtrees.
Given a list of employee IDs, construct a Binary Search Tree and print the preorder traversal of the BST

Input Format
The first line contains an integer n, representing the number of employees.
The second line contains n integers representing the employee IDs to be inserted into the BST.

Output Format
Print a single line containing the preorder traversal of the Binary Search Tree.

Sample Input 
7
40 20 60 10 30 50 70

Sample Output
40 20 10 30 60 50 70
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
// print in pre-order
void preorder(struct node *root){
  if(root == NULL) return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
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
  preorder(root);
  return 0;
}
