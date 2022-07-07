#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
We have the inorder and postorder traversal sequence of a binary
tree to generate the Binary tree Asked in : Samsung, WalmartLabs

*/

// Data structure to store a Binary Tree node
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
  node->left = node->right = nullptr;

  return node;
}

int search(vector<int> &arr, int start, int end, int key);

// Function to print the inorder traversal of a binary tree
void pre(Node *root)
{
  if (root == nullptr)
    return;

  cout << root->data << ' ';

  pre(root->left);
  pre(root->right);
}

// Recursive function to build a binary search tree from
// its postorder sequence
Node *buildTreeUtil(vector<int> &post, vector<int> &in, int *current,
                    int min, int max)
{
  if (min > max)
  {
    return NULL;
  }

  Node *node = newNode(post[*current]);
  (*current)--;

  if (min == max)
  {
    return node;
  }

  int iIndex = search(in, min, max, node->data);

  node->right = buildTreeUtil(post, in, current, iIndex + 1, max);
  node->left = buildTreeUtil(post, in, current, min, iIndex - 1);

  return node;
}

// Build a binary search tree from its postorder sequence
Node *buildTree(vector<int> &post, vector<int> &in, int n)
{
  int pIndex = n - 1;
  return buildTreeUtil(post, in, &pIndex, 0, n - 1);
}

int search(vector<int> &arr, int start, int end, int key)
{
  int i = 0;
  for (i = 0; i <= end; i++)
  {
    if (arr[i] == key)
    {
      break;
    }
  }
  return i;
}

int main()
{
  /* Construct below BST
        15
      /	\
       /	  \
      10	   20
     /  \	 /  \
    /	\   /	\
     8	 12 16	25
  */

  // postorder traversal of BST
  vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
  vector<int> post = {8, 4, 5, 2, 6, 7, 3, 1};

  // construct the BST
  Node *root = buildTree(post, in, in.size());

  // print the BST
  cout << "Inorder Traversal of BST is : ";

  // inorder on the BST always returns a sorted sequence
  pre(root);

  return 0;
}

/* Try more Inputs
Case 1:
int[] inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
int[] postorder = { 4, 2, 7, 8, 5, 6, 3, 1};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [4, 2, 1, 7, 5, 8, 3, 6]

Case2:
int[] inorder = { 9,3,15,20,7 };
int[] postorder = { 9,15,7,20,3};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [9,3,15,20,7]
*/
