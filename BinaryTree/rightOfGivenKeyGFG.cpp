#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
  struct Node *left, *right;
  int key;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
  Node *temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

// Function to find next node for given node
// in same level in a binary tree by using
// pre-order traversal
Node *nextRightNode(Node *root, int k, int level,
                    int &value_level)
{
  // return null if tree is empty
  if (root == NULL)
    return NULL;

  // if desired node is found, set value_level
  // to current level
  if (root->key == k)
  {
    value_level = level;
    return NULL;
  }

  // if value_level is already set, then current
  // node is the next right node
  else if (value_level)
  {
    if (level == value_level)
      return root;
  }

  // recurse for left subtree by increasing level by 1
  Node *leftNode = nextRightNode(root->left, k,
                                 level + 1, value_level);

  // if node is found in left subtree, return it
  if (leftNode)
    return leftNode;

  // recurse for right subtree by increasing level by 1
  return nextRightNode(root->right, k, level + 1,
                       value_level);
}

// Function to find next node of given node in the
//  same level in given binary tree
Node *nextRightNodeUtil(Node *root, int k)
{
  int value_level = 0;

  return nextRightNode(root, k, 1, value_level);
}

// A utility function to test above functions
void test(Node *root, int k)
{
  Node *nr = nextRightNodeUtil(root, k);
  if (nr != NULL)
    cout << "Next Right of " << k << " is "
         << nr->key << endl;
  else
    cout << "No next right node found for "
         << k << endl;
}

// Driver program to test above functions
int main()
{
  // Let us create binary tree given in the
  // above example
  Node *root = newNode(10);
  root->left = newNode(2);
  root->right = newNode(6);
  root->right->right = newNode(5);
  root->left->left = newNode(8);
  root->left->right = newNode(4);

  test(root, 10);
  test(root, 2);
  test(root, 6);
  test(root, 5);
  test(root, 8);
  test(root, 4);
  return 0;
}