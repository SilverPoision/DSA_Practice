#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, determine if it is a valid binary search
tree (BST). Assume a BST is defined as follows: The left subtree
of a node contains only nodes with keys less than the node's
key. The right subtree of a node contains only nodes with keys
greater than the node's key. Both the left and right subtrees
must also be binary search trees
*/

// Data structure to store a Binary Search Tree node
class node
{
public:
  int data;
  node *left, *right;

  // Function to create a new binary tree node having given key
  node(int key)
  {
    this->data = key;
    this->left = this->right = nullptr;
  }
};

int isBSTUtil(node *root, int min, int max)
{
  if (root == NULL)
  {
    return 1;
  }

  if (root->data > max || root->data < min)
  {
    return 0;
  }
  return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

int isBST(node *node)
{
  return (isBSTUtil(node, INT_MIN, INT_MAX));
}

int main()
{
  node *root = new node(4);
  root->left = new node(2);
  root->right = new node(5);
  root->left->left = new node(1);
  root->left->right = new node(3);

  if (isBST(root))
    cout << "Is BST";
  else
    cout << "Not a BST";

  return 0;
}

/*bool Bleft = true, Bright = true;

// Function to determine if given Binary Tree is a BST or not
bool isBST(Node *root)
{
  if (root == NULL)
  {
    return true;
  }

  if (!root->left && !root->right)
  {
    return true;
  }

  if (root->left->data < root->data && root->right->data > root->data || root->left && !root->right && root->left->data < root->data || root->right && !root->left && root->right->data > root->data)
  {
    if (Bleft == true && Bright == true)
    {
      Bleft = isBST(root->left);
      Bright = isBST(root->right);
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }

  return true;
}*/