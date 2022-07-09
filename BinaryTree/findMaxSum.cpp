#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
};

struct Node *newNode(int data)
{
  struct Node *newNode = new Node;
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return (newNode);
}

int res = INT_MIN;
int findMaxSum(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int left = findMaxSum(root->left);
  int right = findMaxSum(root->right);

  int max_value = max(max(left, right) + root->data, root->data);
  int max_top = max(max_value, left + right + root->data);
  res = max(res, max_top);
  return max_value;
}

int main(void)
{
  struct Node *root = newNode(10);
  root->left = newNode(2);
  root->right = newNode(15);
  root->left->left = newNode(-4);
  root->left->right = newNode(-6);
  root->left->left->left = newNode(28);
  root->left->left->right = newNode(-22);
  root->right->right = newNode(-25);
  root->right->right->left = newNode(3);
  root->right->right->right = newNode(4);
  findMaxSum(root);
  cout << "Max path sum  " << res;
  return 0;
}

/* Try more Inputs
case1:
root = None
root = newNode(1)
root.left = newNode(2)
root.right = newNode(3)
resultRoot = maxPathUtility(root)
expected = 6

case2:
Node root = new Node(1);
root.left = new Node(2);
root.right = new Node(10);
root.left.left = new Node(-1);
root.left.right = new Node(-4);
root.right.left = new Node(-5);
root.right.right = new Node(-6);
root.left.right.left = new Node(4);
root.right.left.left = new Node(7);
root.right.left.right = new Node(4);
root.right.left.left.right = new Node(-2);
actual = maxPathUtility(root)
expected = 19
*/
