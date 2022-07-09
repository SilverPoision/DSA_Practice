#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

/* Iterative function for inorder tree
   traversal */
void iterativeINorder(Node *root)
{
  if (root == NULL)
    return;

  stack<Node *> Stack;
  Node *n1 = root;

  while (n1 != NULL || Stack.empty() == false)
  {
    while (n1)
    {
      Stack.push(n1);
      n1 = n1->left;
    }
    n1 = Stack.top();
    Stack.pop();
    cout << n1->data << " ";
    n1 = n1->right;
  }
}

int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  iterativeINorder(root);
  return 0;
}