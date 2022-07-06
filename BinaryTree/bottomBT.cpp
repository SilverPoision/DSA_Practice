#include <bits/stdc++.h>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
  int key;
  Node *left, *right;

  Node(int key)
  {
    this->key = key;
    this->left = this->right = nullptr;
  }
};

void printBottomUtil(Node *root, map<int, pair<int, int>> &Map, int HD, int level)
{
  if (root == NULL)
    return;

  if (Map.find(HD) == Map.end())
  {
    Map[HD] = {root->key, level};
  }
  else
  {
    if (Map[HD].second <= level)
    {
      Map[HD] = {root->key, level};
    }
  }

  printBottomUtil(root->left, Map, HD - 1, level + 1);
  printBottomUtil(root->right, Map, HD + 1, level + 1);
}

// Function to print the bottom view of given binary tree
void printBottom(Node *root)
{
  map<int, pair<int, int>> Map;

  printBottomUtil(root, Map, 0, 0);

  for (auto it : Map)
  {
    cout << it.second.first << " ";
  }
}

int main()
{
  Node *root = nullptr;

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(5);
  root->right->right = new Node(6);
  root->right->left->left = new Node(7);
  root->right->left->right = new Node(8);

  printBottom(root);

  return 0;
}

/* Try more Inputs
Case 1:
result = []
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
root.right.left = new Node(4);
root.right.right = new Node(25);
root.left.right.left = new Node(10);
root.left.right.right = new Node(14);
result = printBottom(root)
expected = [5,10,4,14,25]

Case2:
Node root = new Node(20);
root.left = new Node(8);
root.right = new Node(22);
root.left.left = new Node(5);
root.left.right = new Node(3);
printBottom(root)
expected = [5,3,22]
*/
