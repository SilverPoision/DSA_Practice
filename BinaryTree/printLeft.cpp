#include <bits/stdc++.h>
using namespace std;

/*
Printing the left view of a binary tree involves
printing the left-most node, at each level, in the
binary tree In Time Complexity O(n) and Space
Complexity O(n) Asked in : Amazon, EMC2, SAP-Labs

*/

class node
{
public:
  int data;
  node *left, *right;
};

node *newNode(int item)
{
  node *temp = new node();
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Recursive function to print left view of a binary tree.
void leftViewPrint(node *root, int VD, int *max)
{
  if (root == NULL)
  {
    return;
  }

  if (*max < VD)
  {
    cout << root->data << " ";
    *max = VD;
  }

  leftViewPrint(root->left, VD + 1, max);
  leftViewPrint(root->right, VD + 1, max);
}

void leftView(node *root)
{
  int max = 0;
  leftViewPrint(root, 1, &max);
}

int main()
{
  node *root = newNode(10);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(7);
  root->left->right = newNode(8);
  root->right->right = newNode(15);
  root->right->left = newNode(12);
  root->right->right->left = newNode(14);
  leftView(root);

  return 0;
}

/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
tree.root = new Node(12);
tree.root.left = new Node(10);
tree.root.right = new Node(30);
tree.root.right.left = new Node(25);
tree.root.right.right = new Node(40);
printLeftView(root)
expected = [12,10,25]

Case2:
BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
root.right.left.right.left = newNode(18);
root.right.left.right.right = newNode(7);
printLeftView(root)
expected = [10,12,4,6,18]
*/