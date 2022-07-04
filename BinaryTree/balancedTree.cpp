#include <bits/stdc++.h>
using namespace std;

/*
For this problem, a height-balanced binary tree is defined as: a
binary tree in which the left and right subtrees of every node
differ in height by no more than 1
*/

class node
{
public:
  int data;
  node *left;
  node *right;
};

int height(node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node *root)
{
  int left, right = 0;

  if (root == NULL)
  {
    return 1;
  }

  left = height(root->left);
  right = height(root->right);

  if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
  {
    return true;
  }
  return false;
}

node *newNode(int data)
{
  node *Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;

  return (Node);
}

int main()
{
  int height = 0;

  /* Constructed binary tree is
          1
          / \
          2 3
          / \ /
          4 5 6
          /
          7
  */
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(8);

  if (isBalanced(root))
    cout << "Tree is balanced";
  else
    cout << "Tree is not balanced";

  return 0;
}

/* Try more Inputs
case1:
root = Node(2)
root.left = Node(3)
root.right = Node(4)
root.left.left = Node(5)
root.left.right = Node(6)
root.left.left.left = Node(9)
actual = isTreeBalanced(root)
expected = True

case2:
root = Node(2)
root.left = Node(3)
root.right = Node(4)
root.left.left = Node(5)
root.left.left.left = Node(6)
root.left.left.left.left = Node(9)
actual = isTreeBalanced(root)
expected = False

*/