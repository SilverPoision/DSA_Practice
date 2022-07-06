#include <iostream>
using namespace std;

/*
Find All Nodes Distance K in Binary Tree

Solution:
https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
*/

struct node
{
  int data;
  struct node *left, *right;
};

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
void findNodeDown(node *Node, int k)
{
  if (Node == NULL)
  {
    return;
  }
  if (k == 0)
  {
    cout << Node->data << endl;
    return;
  }

  findNodeDown(Node->left, k - 1);
  findNodeDown(Node->right, k - 1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(node *root, node *target, int k)
{
  if (root == NULL)
  {
    return -1;
  }
  if (root == target)
  {
    return 1;
  }

  int dLeft = printkdistanceNode(root->left, target, k);
  if (dLeft != -1)
  {
    if (dLeft == k)
    {
      cout << root->data << endl;
    }
    else
    {
      findNodeDown(root->right, k - dLeft - 1);
    }

    return dLeft + 1;
  }

  int dRight = printkdistanceNode(root->right, target, k);
  if (dRight != -1)
  {
    if (dRight == k)
    {
      cout << root->data << endl;
    }
    else
    {
      findNodeDown(root->left, k - dRight - 1);
    }

    return dRight + 1;
  }
  return -1;
}

node *newnode(int data)
{
  node *temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int main()
{

  node *root = newnode(22);
  root->left = newnode(18);
  root->right = newnode(23);
  root->left->left = newnode(14);
  root->left->right = newnode(11);
  root->left->right->left = newnode(9);
  root->left->right->right = newnode(10);
  node *target = root->left->right;
  printkdistanceNode(root, target, 2);
  return 0;
}