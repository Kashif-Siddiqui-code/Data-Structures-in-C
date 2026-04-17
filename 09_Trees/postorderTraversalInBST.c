/*
Problem Description:
Banking Transaction System
In a banking transaction system, customer account numbers are stored in a Binary Search Tree (BST) to enable fast searching and secure storage.
Each node in the BST represents a customer account number.
Account numbers are inserted into the BST one by one.
Before shutting down the system for maintenance, the bank performs a postorder traversal of the BST to safely close all account records, since postorder traversal
processes child nodes before the parent node.
Given a list of customer account numbers, construct a Binary Search Tree and print the postorder traversal of the BST.

Input Format
The first line contains an integer n, representing the number of customer accounts.
The second line contains n integers representing the account numbers to be inserted into the BST.

Output Format
Print a single line containing the postorder traversal of the Binary Search Tree.

Sample Input
7
40 20 60 10 30 50 70

Sample Output
10 30 20 50 70 60 40
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
// print in postorder
void postorder(struct node *root){
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
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
  postorder(root);
  return 0;
}


