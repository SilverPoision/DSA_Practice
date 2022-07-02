#include <bits/stdc++.h>
using namespace std;

/*
Mirror of a Tree: Mirror of a Binary Tree T is another Binary
Tree M(T) with left and right children of all non-leaf nodes
interchanged
*/

/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  Node(int value)
  {
    data = value;
    left = right = NULL;
  }
};

struct Node *newNode(int data)
{
  struct Node *node = (struct Node *)
      malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

/* Change a tree so that the roles of the left and
    right pointers are swapped at every node.

So the tree...
     4
    / \
    2 5
    / \
    1 3

is changed to...
    4
    / \
    5 2
    / \
    3 1
*/
void findMirror(struct Node *node)
{
  if (node == NULL)
    return;

  struct Node *temp;
  findMirror(node->left);
  findMirror(node->right);

  temp = node->left;
  node->left = node->right;
  node->right = temp;
}

void inOrder(struct Node *node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  cout << node->data << " ";
  inOrder(node->right);
}

int main()
{
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  /* Print inorder traversal of the input tree */
  cout << "Inorder traversal of the constructed"
       << " tree is" << endl;
  inOrder(root);

  /* Convert tree to its mirror */
  findMirror(root);

  /* Print inorder traversal of the mirror tree */
  cout << "\nInorder traversal of the mirror tree"
       << " is \n";
  inOrder(root);

  return 0;
}