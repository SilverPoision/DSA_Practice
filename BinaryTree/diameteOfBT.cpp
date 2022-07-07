#include <bits/stdc++.h>
using namespace std;

/*
The diameter of a binary tree is the length of the longest path
between any two nodes in a tree. Find diameter of tree in Time
Complexity O(n) Asked in : Flipkart, Amazon, Microsoft, Facebook, Intuit, Broadcom

T-C = log(n2) where n is no of leaf nodes.
*/

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

int findLeaves(Node *root, vector<int> &leaf)
{
  if (root == NULL)
  {
    return -1;
  }

  if (root->left == NULL && root->right == NULL)
  {
    leaf.push_back(root->data);
    return 1;
  }

  findLeaves(root->left, leaf);
  findLeaves(root->right, leaf);
}

int funcDriver(Node *root, vector<int> &leaf)
{
  int max = INT_MIN;
  findLeaves(root, leaf);
  for (int i = 0; i < leaf.size(); i++)
  {
    for (int j = 0; j < leaf.size(); j++)
    {
      int t = findDistance(root, leaf[i], leaf[j]);
      if (max < t)
      {
        max = t;
      }
    }
  }
  return max + 1;
}

int main()
{

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<int> leaf;

  cout << "The diameter of the tree is " << funcDriver(root, leaf);

  return 0;
}