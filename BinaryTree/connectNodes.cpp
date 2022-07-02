#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
  int data;
  Node *left, *right, *next;

  // constructor
  Node(int data)
  {
    this->data = data;
    this->left = this->right = this->next = nullptr;
  }
};

// Function to print a given linked list
void printList(Node *head)
{
  while (head)
  {
    cout << head->data << " -> ";
    head = head->next;
  }

  cout << "null" << '\n';
}

// Recursive function to find the first node in next level of the root node
Node *findNextNode(Node *root)
{
  if (root == nullptr || root->next == nullptr)
  {
    return nullptr;
  }
  if (root->next->left)
  {
    return root->next->left;
  }

  if (root->next->right)
  {
    return root->next->right;
  }
  return findNextNode(root->next);
}

// Recursive function to link nodes present in each level of a binary tree
// in the form of a linked list
void linkNodes(Node *root)
{
  if (root == nullptr)
  {
    return;
  }
  linkNodes(root->next);

  // update the next pointer of root's left child to root's right child
  // if right child doesn't exist, link it to first node in the next level
  if (root->left)
  {
    root->left->next = (root->right) ? root->right : findNextNode(root);
  }

  // update the next pointer of root's right child to first node
  // in the next level
  if (root->right)
  {
    root->right->next = findNextNode(root);
  }

  linkNodes(root->right);
  linkNodes(root->left);
}

int main()
{
  /* Construct below Tree
         1
       /   \
      2  -- 3
     / \     \
    4 --5 --  6
     \       /
      7     8
  */

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  root->left->left->right = new Node(7);
  root->right->right->left = new Node(8);

  // link nodes at the same level
  linkNodes(root);

  // print the nodes
  Node *node = root;
  while (node)
  {
    // print current level
    printList(node);

    // find leftmost node of the next level
    if (node->left)
      node = node->left;
    else if (node->right)
      node = node->right;
    else
      node = findNextNode(node);
  }

  return 0;
}
