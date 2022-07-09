#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;

  Node(int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// Function to print pre-order traversal of given tree
void printInorder(Node *Node)
{
  if (Node == NULL)
    return;
  printInorder(Node->left);
  cout << " " << Node->data;
  printInorder(Node->right);
}

// Recursive function to in-place convert the given binary tree to its
// sum tree by traversing the tree in postorder manner
int convertToSumTree(Node *root)
{
  if (root == NULL)
    return 0;

  int left = convertToSumTree(root->left);
  int right = convertToSumTree(root->right);

  int prev = root->data;

  root->data = left + right;

  return prev + root->data;
}

int main()
{
  Node *root = nullptr;

  root = new Node(10);
  root->left = new Node(-2);
  root->right = new Node(6);
  root->left->left = new Node(8);
  root->left->right = new Node(-4);
  root->right->left = new Node(7);
  root->right->right = new Node(5);

  convertToSumTree(root);
  printInorder(root);

  return 0;
}