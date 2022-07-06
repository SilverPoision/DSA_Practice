#include <iostream>
using namespace std;

/*
Convert BT to DLL such that the left pointer of the node should
be pointing to the previous node in the doubly linked list, and
the right pointer should be pointing to the next node in the
doubly linked list in Time Complexity O(n) and Space O(Height)
Asked in : Amazon, Microsoft, Flipkart, WalmartLabs
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

// in-place convert given Binary Tree to a Doubly Linked List
Node *parent;
void convert(Node *root, Node **head)
{
  if (root == NULL)
  {
    return;
  }

  static Node *prev = NULL;

  convert(root->left, head);
  if (prev == NULL)
  {
    *head = root;
  }
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  convert(root->right, head);
}

void printList(Node *node)
{

  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->right;
  }
}

int main()
{
  /* Construct below tree
            1
         /     \
        2       3
       / \     / \
      4   5   6   7
  */

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  Node *head = NULL;

  convert(root, &head);

  printList(head);

  return 0;
}
/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
BinaryTree tree = new BinaryTree();
tree.root = new Node(10);
tree.root.left = new Node(12);
tree.root.right = new Node(15);
tree.root.left.left = new Node(25);
tree.root.left.right = new Node(30);
tree.root.right.left = new Node(36);
display(root)
expected = [25 ,12 ,30 ,10 ,36 ,15]

Case 1:
BinaryTree tree = new BinaryTree();
BinaryTree tree = new BinaryTree();
tree.root = new Node(10);
tree.root.left = new Node(12);
display(root)
expected = [12,10]

*/

// void convert(Node *root, Node **root2)
// {
//   if (root == NULL)
//   {
//     return;
//   }

//   static Node *prev = NULL;

//   convert(root->left, root2);
//   if (prev == NULL)
//   {
//     *root2 = root;
//   }
//   else
//   {
//     root->left = prev;
//     prev->right = root;
//   }
//   prev = root;
//   convert(root->right, root2);
// }

// void printList(Node *node)
// {
//   while (node != NULL)
//   {
//     cout << node->data << " ";
//     node = node->right;
//   }
// }