#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */

class node
{
public:
  int data;
  node *left;
  node *right;

  /* Constructor that allocates a new node with the
  given data and NULL left and right pointers. */

  node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void printKDistance(node *root, int k)
{

  if (root == NULL)
  {
    return;
  }

  // cout << count << endl;
  if (k == 0)
  {
    cout << root->data << endl;
    return;
  }

  printKDistance(root->left, k - 1);
  printKDistance(root->right, k - 1);
}

int main()
{

  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(8);

  printKDistance(root, 2);
  return 0;
}

/* Try more Inputs

/* Constructed binary tree is
             1
            / \
           2   3
          / \ /
         4  5 8
    */
/*Case 1:
Main tree = new Main();
tree.root = new Node(1);
tree.root.left = new Node(2);
tree.root.right = new Node(3);
tree.root.left.left = new Node(4);
tree.root.left.right = new Node(5);
tree.root.right.left = new Node(8);
tree.printLeftView(tree.root,2)
expected = [4,5,8]*/

// Case2:
/* Constructed binary tree is
             10
            / \
           12  3
           \  /
            4 5
                \
                 6
*/
/*BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
tree.printLeftView(root,2)
expected = [4,5]
*/