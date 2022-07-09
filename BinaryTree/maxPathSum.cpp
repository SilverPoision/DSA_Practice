#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
public:
  int data;
  node *left;
  node *right;
};

// A utility function that prints all nodes
// on the path from root to target_leaf
int maxi, maxiSum = 0;

bool printPath(node *root,
               node *target_leaf)
{
  // base case
  if (root == NULL)
    return false;

  // return true if this node is the target_leaf
  // or target leaf is present in one of its
  // descendants
  if (root == target_leaf || printPath(root->left, target_leaf) ||
      printPath(root->right, target_leaf))
  {
    maxi += root->data;
    if (maxi > maxiSum)
    {
      maxiSum = maxi;
    }
    return true;
  }

  return false;
}

node *maxSum(node *root, vector<node *> &arr)
{
  if (root == NULL)
    return NULL;

  if (root->left == NULL && root->right == NULL)
  {
    arr.push_back(root);
    return root;
  }

  maxSum(root->left, arr);
  maxSum(root->right, arr);
}

// Returns the maximum sum and prints the nodes on max
// sum path

/* Utility function to create a new Binary Tree node */
node *newNode(int data)
{
  node *temp = new node;
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int main()
{
  node *root = NULL;

  /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(7);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);

  vector<node *> arr;
  maxSum(root, arr);

  cout << "Following are the nodes on the maximum "
          "sum path \n";
  for (auto it : arr)
  {
    maxi = 0;
    printPath(root, it);
  }

  cout << "\nSum of the nodes is " << maxiSum;
  return 0;
}