#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
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

// given binary tree rooted at 'root' node
Node *findLCA(Node *root, int x, int y)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (root->data == x || root->data == y)
  {
    return root;
  }

  Node *left = findLCA(root->left, x, y);
  Node *right = findLCA(root->right, x, y);

  if (left && right)
  {
    return root;
  }

  return (left != NULL ? left : right);
}

int Level(Node *root, int x, int pointer)
{
  if (root == NULL)
  {
    return -1;
  }

  if (root->data == x)
  {
    return pointer;
  }

  int left = Level(root->left, x, pointer + 1);
  if (left == -1)
  {
    return Level(root->right, x, pointer + 1);
  }
  return left;
}

int findDistance(Node *root, int x, int y)
{

  Node *lca = findLCA(root, x, y);
  int distX = Level(lca, x, 0);
  int distY = Level(lca, y, 0);
  return abs(distX + distY);
}

int main()
{
  Node *root = nullptr;
  /* Construct below tree
        1
      /   \
     /     \
    2       3
     \     / \
      4   5   6
         / \
        7   8
  */

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->right->right = new Node(8);

  // find distance between node 7 and node 6
  cout << findDistance(root, 8, 4);

  return 0;
}