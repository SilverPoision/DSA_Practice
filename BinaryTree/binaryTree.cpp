#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int item)
  {
    data = item;
    left = right = NULL;
  }
};

void InOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  InOrder(node->left);
  cout << node->data << endl;
  InOrder(node->right);
}

void postOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  postOrder(node->left);
  postOrder(node->right);
  cout << node->data << endl;
}

void preOrder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->data << endl;

  preOrder(node->left);
  preOrder(node->right);
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  root->left->left->right = new Node(7);
  root->right->right->left = new Node(8);
  postOrder(root);
  return 0;
}