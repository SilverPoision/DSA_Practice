#include <iostream>
#include <list>
using namespace std;

/*
Given a Binary tree and a key in the binary tree, find the node
right to the given key. If there is no node on right side, then
return NULL. Expected time complexity is O(n) where n is the
number of nodes in the given binary tree

Solution :
1. declare a var poition and increaseits value everytime you go deep into the tree
untile you find the ele.
2. Once you have found the ele juts checkif it is left and it has its right
then just return right and if not then go the right og the bt
in the same level by decrimenting the position value and check if
left exists if yes then return left or return right.
*/

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

// Function to find next node of given node in the same level
// in given binary tree

Node *findNode(Node *root)
{
  if (root == NULL)
  {
    return nullptr;
  }
  return root->right;
}

void findRightNode(Node *root, int val, int pos, Node *root2)
{
  if (root == NULL)
  {
    return;
  }

  if (root->key == val)
  {
    return;
  }

  if (!root->left || !root->right)
  {
    return;
  }

  // cout << root->left->key << " " << root->right->key << endl;

  if (root->left->key == val || root->right->key == val)
  {
    if (root->left->key == val && root->right)
    {
      cout << root->right->key << endl;
      return;
    }

    while (pos > 0)
    {
      root2 = findNode(root2);
      pos--;
    }

    if (root2->left)
    {
      cout << root2->left->key << endl;
      return;
    }
    else if (root2->right)
    {
      cout << root2->right->key << endl;
      return;
    }
  }
  else
  {
    pos++;
    findRightNode(root->left, val, pos, root2);
    findRightNode(root->right, val, pos, root2);
  }

  return;
}

int main()
{
  Node *root = nullptr;

  /* Construct below Tree
            1
          /  \
         /    \
        2      3
       / \      \
      4   5      6
                / \
               7   8
  */

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->left->left = new Node(7);
  root->right->left->right = new Node(8);

  Node *root2 = root;
  findRightNode(root, 5, 0, root2);
  return 0;
}
/* Try more Inputs
case1:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.left.left = Node(7)
root.right.left.right = Node(8)
actual = findRightNode(root, 5)
expected = 6

case2:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.left.left = Node(7)
root.right.left.right = Node(8)
actual = findRightNode(root, 2)
expected = 3

case3:
root = Node(1)
root.left = Node(2)
root.right = Node(3)
actual = findRightNode(root, 2)
expected = 3

*/
