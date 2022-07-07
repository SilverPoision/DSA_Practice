#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
  int data;
  Node *left, *right;
};

// Function to create a new binary tree node having given key
Node *newNode(int key)
{
  Node *node = new Node;
  node->data = key;
  node->left = node->right = nullptr;

  return node;
}

// Function to print the inorder traversal of a binary tree
void inorder(Node *root)
{
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->data << ' ';
  inorder(root->right);
}

// Recursive function to build a binary search tree from
// its postorder sequence
Node *buildTree(vector<int> const &postorder, int &current,
                int min, int max)
{
  // Base case
  if (current < 0)
    return nullptr;

  // Return if next element of postorder traversal from the end
  // is not in valid range
  int curr = postorder[current];
  if (curr < min || curr > max)
    return nullptr;

  // Construct the root node and decrement pIndex
  Node *root = newNode(curr);
  current--;

  // Construct left and right subtree of the root node.
  // Build right subtree before left subtree since the values are
  // being read from the end of the postorder sequence

  // Since all elements in the right subtree of a BST must be greater
  // than the value of root node, set range as [curr+1..max] and recur
  root->right = buildTree(postorder, current, curr + 1, max);

  // Since all elements in the left subtree of a BST must be less
  // than the value of root node, set range as [min, curr-1] and recur
  root->left = buildTree(postorder, current, min, curr - 1);

  return root;
}

// Build a binary search tree from its postorder sequence
Node *buildTree(vector<int> const &postorder)
{
  // start from the root node (last element in postorder sequence)
  int postIndex = postorder.size() - 1;

  // set range of the root node as [INT_MIN, INT_MAX] and recur
  return buildTree(postorder, postIndex, INT_MIN, INT_MAX);
}

int main()
{
  /* Construct below BST
        15
      /	\
       /	  \
      10	   20
     /  \	 /  \
    /	\   /	\
     8	 12 16	25
  */

  // postorder traversal of BST
  vector<int> postorder = {8, 12, 10, 16, 25, 20, 15};

  // construct the BST
  Node *root = buildTree(postorder);

  // print the BST
  cout << "Inorder Traversal of BST is : ";

  // inorder on the BST always returns a sorted sequence
  inorder(root);

  return 0;
}

/* Try more Inputs
Case 1:
int[] inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
int[] postorder = { 4, 2, 7, 8, 5, 6, 3, 1};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [4, 2, 1, 7, 5, 8, 3, 6]

Case2:
int[] inorder = { 9,3,15,20,7 };
int[] postorder = { 9,15,7,20,3};
int result = [];
Node root = construct(inorder, postorder);
inorderTraversal(root,result);
expected = [9,3,15,20,7]
*/