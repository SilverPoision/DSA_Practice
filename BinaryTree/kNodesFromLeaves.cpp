#include <iostream>
using namespace std;
#define MAX_HEIGHT 10000

/*
Print All Nodes K Distance from Leaf Node in Binary Tree


Solution:
The idea is to traverse the tree. Keep storing all ancestors
till we hit a leaf node. When we reach a leaf node, we print
the ancestor at distance k. We also need to keep track of nodes
that are already printed as output. For that we use a boolean
array visited[].
*/

struct Node
{
  int key;
  Node *left, *right;
};

Node *insertNode(int key)
{
  Node *node = new Node;
  node->key = key;
  node->left = node->right = NULL;
  return (node);
}

void nodesKatDistance(Node *node, int path[], bool visited[], int pathLen, int k)
{
  if (node == NULL)
  {
    return;
  }

  path[pathLen] = node->key;
  visited[pathLen] = false;
  pathLen++;

  if (!node->left && !node->right && (pathLen - k - 1) >= 0 && visited[pathLen - k - 1] == false)
  {
    cout << path[pathLen - k - 1] << " ";
    visited[pathLen - k - 1] = true;
    return;
  }

  nodesKatDistance(node->left, path, visited, pathLen, k);
  nodesKatDistance(node->right, path, visited, pathLen, k);
}

void printNodes(Node *node, int k)
{
  int path[MAX_HEIGHT];
  bool visited[MAX_HEIGHT] = {false};
  nodesKatDistance(node, path, visited, 0, k);
}

int main()
{
  Node *root = insertNode(1);
  root->left = insertNode(2);
  root->right = insertNode(3);
  root->left->left = insertNode(4);
  root->left->right = insertNode(5);
  root->right->left = insertNode(6);
  root->right->right = insertNode(7);
  root->right->left->right = insertNode(8);

  cout << "Nodes at distance 2 are: ";
  printNodes(root, 2);

  return 0;
}

/* Try more Inputs
case1:
root = Node(3);
root.left = Node(8);
root.right = Node(9);
root.left.left = Node(11);
root.left.right = Node(7);
root.left.right.left = Node(6);
root.left.right.right = Node(12);
root.right.left = Node(8);
root.right.right = Node(3);
actual = printKDistantfromLeaf(root,3)
expected = 3

case2:
root = Node(3);
root.left = Node(8);
root.right = Node(9);
root.left.left = Node(11);
root.left.right = Node(7);
root.left.right.left = Node(6);
root.left.right.right = Node(12);
root.right.left = Node(8);
root.right.right = Node(3);
actual = printKDistantfromLeaf(root,3)
expected = {3,8}


*/