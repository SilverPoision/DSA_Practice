#include <iostream>
using namespace std;

// A BST node
struct Node
{
  int data;
  Node *left, *right;
  Node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

// Recursive function to insert an key into BST
Node *insert(Node *root, int x)
{
  if (root == NULL)
    return new Node(x);
  if (x < root->data)
    root->left = insert(root->left, x);
  else if (x > root->data)
    root->right = insert(root->right, x);
  return root;
}

// Function to find k'th largest element in BST

void printKthSmallest(Node *root, int k)
{
  if (root == NULL)
  {
    return;
  }

  printKthSmallest(root->left, k);
  k--;
  if (k == 0)
  {
    cout << root->data << endl;
  }
  printKthSmallest(root->right, k);
}

// main function
int main()
{
  Node *root = NULL;
  int keys[] = {13, 14, 22, 25, 23, 32, 26, 28, 40};

  for (int x : keys)
    root = insert(root, x);

  int k = 3;
  printKthSmallest(root, k);
  return 0;
}

/* Try more Inputs

case1:
keys = [13, 14, 22, 25, 23, 32, 26,28,40]
root = insert(root, key)
actual = printKthSmallest(root,3)
expected = 22

case2:
keys = [5,3,6,2,4,1]
root = insert(root, key)
actual = printKthSmallest(root,3)
expected = 3

*/