#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, find the lowest common ancestor (LCA) of
two given nodes in the tree Let T be a rooted tree. The lowest
common ancestor between two nodes n1 and n2 is defined as the
lowest node in T that has both n1 and n2 as descendants
*/

// Data structure to store a Binary Tree node
struct Node
{
  int data;
  Node *left, *right;

  Node(int data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

bool findLCAUtil(Node *root, int n1, vector<int> &arr)
{
  if (root == NULL)
    return false;

  arr.push_back(root->data);

  if (root->data == n1)
  {
    return true;
  }

  if ((root->left && findLCAUtil(root->left, n1, arr)) || (root->right && findLCAUtil(root->right, n1, arr)))
  {
    return true;
  }
  arr.pop_back();
  return false;
}

int findLCA(Node *root, int n1, int n2)
{
  vector<int> path1, path2;
  if (!findLCAUtil(root, n1, path1) || !findLCAUtil(root, n2, path2))
  {
    return -1;
  }

  int i;
  for (i = 0; i < path1.size() && i < path2.size(); i++)
  {
    if (path1[i] != path2[i])
      break;
  }

  return path1[i - 1];
}

int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  cout << findLCA(root, 4, 5) << endl;
  // findLCA(root, root->right->left->left, new Node(10));
  // findLCA(root, root->right->left->left, root->right->left->left);
  // findLCA(root, root->right->left->left, root->right->left);
  // findLCA(root, root->left, root->right->left);

  return 0;
}