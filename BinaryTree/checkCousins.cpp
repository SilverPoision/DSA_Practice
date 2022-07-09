#include <bits/stdc++.h>
using namespace std;

/*
Two nodes of a binary tree are cousins if they have
the same depth, but have different parents. We are
given the root of a binary tree with unique values,
and the values x and y of two different nodes in the
tree. Return true if and only if the nodes
corresponding to the values x and y are cousins
*/

// A Binary Tree Node
struct Node
{
  int data;
  struct Node *left, *right;
};

// A utility function to create a new
// Binary Tree Node
struct Node *newNode(int item)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Returns true if a and b are cousins,
// otherwise false.
int findDepth(Node *root, int a, int depth)
{
  if (root == NULL)
  {
    return -1;
  }

  // cout << root->data << " " << a << endl;

  if (root->data == a)
  {
    return depth;
  }

  int left = findDepth(root->left, a, depth + 1);
  if (left == -1)
  {
    return findDepth(root->right, a, depth + 1);
  }
  return left;
}

bool checkParent(Node *root, int a, int b)
{
  if (root == NULL)
    return false;

  if (root->right && root->left)
  {
    if (root->right->data == a && root->left->data == b || root->right->data == b && root->left->data == a)
    {
      return true;
    }
  }

  if (root->left)
  {
    if (checkParent(root->left, a, b))
    {
      return true;
    }
  }

  if (root->right)
  {
    if (checkParent(root->right, a, b))
    {
      return true;
    }
  }
  return false;
}

bool isCousinFound(Node *root, int a, int b)
{
  bool parent;
  int depthA = findDepth(root, a, 0);
  int depthB = findDepth(root, b, 0);

  if (depthA == depthB)
  {
    parent = !checkParent(root, a, b);
  }

  return parent;
}

int main()
{
  /*
          1
         /  \
        2    3
       / \  / \
      4   5 6  7
           \ \
           15 8
  */

  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->right = newNode(15);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);

  isCousinFound(root, 4, 5) ? puts("Yes") : puts("No");

  return 0;
}