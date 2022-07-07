#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/
*/

/* A binary tree node has data,
pointer to left child and a pointer
to right child */
class node
{
public:
  int data;
  node *left;
  node *right;

  /* Constructor that allocates
  a new node with the given data
  and NULL left and right pointers. */
  node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

struct Info
{
  int sz;
  int max;
  int min;
  int ans; // size of largest bst

  bool isBST;
};

/* Returns size of the largest BST
subtree in a Binary Tree
(efficient version). */
Info largestBST(node *root)
{
  if (root == NULL)
  {
    return {0, INT_MIN, INT_MAX, 0, true};
  }
  if (root->left == NULL && root->right == NULL)
  {
    return {1, root->data, root->data, 1, true};
  }

  Info l = largestBST(root->left);
  Info r = largestBST(root->right);

  Info ret;
  ret.sz = (1 + l.sz + r.sz);

  if (l.isBST && r.isBST && l.max < root->data && r.min > root->data)
  {
    ret.min = min(l.min, min(r.min, root->data));
    ret.max = max(r.max, max(l.max, root->data));

    ret.ans = max(l.ans, r.ans) + 1;
    ret.isBST = true;
    return ret;
  }

  ret.ans = max(l.ans, r.ans);
  ret.isBST = false;

  return ret;
}

int main()
{
  /* Let us construct the following Tree
  50
  / \
  10 60
  / \ / \
5 20 55 70
  / / \
 45 65 80
*/

  node *root = nullptr;
  root = new node(60);
  root->left = new node(65);
  root->right = new node(70);
  root->left->left = new node(50);
  printf(" Size of the largest BST is %d\n",
         largestBST(root).ans);
  return 0;

  /* The complete tree is not BST
  as 45 is in right subtree of 50.
  The following subtree is the largest BST
          60
      / \
      55 70
  / / \
  45 65 80
  */

  return 0;
}