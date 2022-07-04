#include <iostream>
using namespace std;

/*
Given a root node reference of a BST and a key, delete the node
with the given key in the BST. Return the root node reference
(possibly updated) of the BST. Basically, the deletion can be
divided into two stages: Search for a node to remove. If the
node is found, delete the node
*/

// Data structure to store a Binary Search Tree node
struct Node
{
  int data;
  Node *left, *right;
};

// Function to create a new binary tree node having given key
Node *newNode(int key)
{
  Node *node = new Node;
  node->data = key;
  node->left = node->right = NULL;

  return node;
}

// Function to perform inorder traversal of the BST
void inorder(Node *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

// Recursive function to insert a key into BST
Node *insert(Node *root, int key)
{
  // if the root is null, create a new node and return it
  if (root == NULL)
    return newNode(key);

  // if given key is less than the root node, recur for left subtree
  if (key < root->data)
    root->left = insert(root->left, key);

  // if given key is more than the root node, recur for right subtree
  else
    root->right = insert(root->right, key);

  return root;
}

// Function to delete node from a BST
Node *minValueNode(Node *root)
{
  Node *curr = root;
  while (curr && curr->left != NULL)
  {
    curr = curr->left;
  }
  return curr;
}

Node *deleteNode(Node *root, int key)
{
  if (root == NULL)
  {
    return root;
  }

  if (key < root->data)
  {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = deleteNode(root->right, key);
  }
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      return NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main()
{
  Node *root = nullptr;
  int keys[] = {5, 3, 6, 2, 4, NULL, 7};

  for (int key : keys)
    root = insert(root, key);

  inorder(root);
  cout << "\n"
       << endl;
  deleteNode(root, 3);

  inorder(root);

  return 0;
}