#include <bits/stdc++.h>
using namespace std;

/*
Algorithm to print Binary Tree nodes level by level in reverse
order. It means all the nodes at the last level should be printed
first followed by the nodes of second last level and so on in Time
Complexity O(n) and Space Complexity O(n) and Asked in: Sap Labs,
Cisco
*/

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

void reverseLevelOrderUtil(Node *root, int VD, map<int, vector<int>> &Map)
{
  if (root == NULL)
  {
    return;
  }

  Map[VD].push_back(root->key);

  reverseLevelOrderUtil(root->left, VD + 1, Map);
  reverseLevelOrderUtil(root->right, VD + 1, Map);
}

// Function to print reverse level order traversal of given binary tree
void reverseLevelOrder(Node *root)
{
  map<int, vector<int>> Map;
  reverseLevelOrderUtil(root, 0, Map);
  for (auto i = Map.rbegin(); i != Map.rend(); ++i)
  {
    for (auto it2 : Map[i->first])
    {
      cout << it2 << " ";
    }
  }
}

int main()
{
  Node *root = nullptr;

  root = new Node(15);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->left = new Node(8);
  root->left->right = new Node(12);
  root->right->left = new Node(16);
  root->right->right = new Node(25);

  reverseLevelOrder(root);

  return 0;
}

/* Try more Inputs
case1:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
actual = reverseLevelOrder(tree)
expect = 2 3 1

case2:
Node tree = new Node();
tree->root = new Node(1);
tree->root->left = new Node(2);
tree->root->right = new Node(3);
tree->root->right->left = new Node(-4);
tree->root->right->right = new Node(-5);
expect = -4 -5 2 3 1
*/