#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  Node *left, *right;

  Node(int key)
  {
    this->key = key;
    this->left = this->right = nullptr;
  }
};

// Function to print reverse level order traversal of given binary tree
void reverseLevelOrder(Node *root)
{
  if (root == NULL)
    return;

  stack<Node *> Stack;
  queue<Node *> Queue;
  Queue.push(root);

  while (Queue.empty() == false)
  {
    Node *n1 = Queue.front();
    Queue.pop();
    Stack.push(n1);
    if (n1->right)
      Queue.push(n1->right);
    if (n1->left)
      Queue.push(n1->left);
  }

  while (Stack.empty() == false)
  {
    root = Stack.top();
    cout << root->key << " ";
    Stack.pop();
  }
}

int main()
{
  Node *root = nullptr;

  root = new Node(15);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->left = new Node(8);
  root->left->right = new Node(12);
  root->right->left = new Node(16);
  root->right->right = new Node(25);

  reverseLevelOrder(root);

  return 0;
}

/* Try more Inputs
case1:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
actual = reverseLevelOrder(tree)
expect = 2 3 1

case2:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
tree->root->right->left = new Node(-4);
tree->root->right->right = new Node(-5);
expect = -4 -5 2 3 1
*/