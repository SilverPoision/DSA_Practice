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
  bool flip = false;
  if (root == NULL)
    return;

  stack<Node *> Stack1;
  stack<Node *> Stack2;
  Stack1.push(root);

  while (!Stack1.empty() || !Stack2.empty())
  {
    while (!Stack1.empty())
    {
      Node *n1 = Stack1.top();
      Stack1.pop();
      cout << n1->key << " ";

      if (n1->right)
        Stack2.push(n1->right);
      if (n1->left)
        Stack2.push(n1->left);
    }

    while (!Stack2.empty())
    {
      Node *n1 = Stack2.top();
      Stack2.pop();
      cout << n1->key << " ";

      if (n1->left)
        Stack1.push(n1->left);
      if (n1->right)
        Stack1.push(n1->right);
    }
  }
}

int main()
{
  Node *root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(8);
  root->left->right = new Node(7);
  root->right->left = new Node(6);
  root->right->right = new Node(5);

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