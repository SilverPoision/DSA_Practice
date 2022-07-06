#include <iostream>
using namespace std;

/*
Print all the boundary nodes in the binary tree.Boundary
includes left boundary, leaves, and right boundary in anti
clockwise direction in O(n) Time Complexity Asked in :
Flipkart, OLA, InMobi

*/

struct node
{
  int data;
  struct node *left, *right;
};

void printLeft(node *root)
{
  if (root == NULL)
  {
    return;
  }

  if (root->left)
  {
    cout << root->data << " ";
    printLeft(root->left);
  }
  else if (root->right)
  {
    cout << root->data << " ";
    printLeft(root->right);
  }
}

void printRight(node *root)
{
  if (root == NULL)
  {
    return;
  }

  if (root->right)
  {
    printRight(root->right);
    cout << root->data << " ";
  }
  else if (root->left)
  {
    printRight(root->left);
    cout << root->data << " ";
  }
}

void printLeaf(node *root)
{
  if (root == NULL)
  {
    return;
  }
  printLeaf(root->left);

  if (!(root->left) && !(root->right))
  {
    cout << root->data << " ";
  }
  printLeaf(root->right);
}

// A function to do boundary traversal of a given binary tree
void printBoundaryNodes(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  printLeft(root->left);
  printLeaf(root->left);
  printLeaf(root->right);
  printRight(root->right);
}

struct node *newNode(int data)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));

  temp->data = data;
  temp->left = temp->right = NULL;

  return temp;
}

int main()
{

  /*
                20
               /  \
             8     22
            / \     \
           14  16     25
              /  \
             9    17
  */

  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->right = newNode(10);
  root->right->right->left = newNode(11);
  root->left->left->right->left = newNode(12);
  root->left->left->right->right = newNode(13);
  root->right->right->left->left = newNode(14);
  printBoundaryNodes(root);

  return 0;
}

/* Try more Inputs
Case1:
struct node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = nnewNode(6);
root->right->right = newNode(7);
root->left->left->left = newNode(8);
root->left->left->right = newNode(9);
root->left->right->right = new Node(10);
root->right->right->left = new Node(11);
root->left->left->right->left = new Node(12);
root->left->left->right->right = new Node(13);
root->right->right->left->left = new Node(14);
printLeftView(root)
expected = [1,2,4,8,12,13,10,6,14,11,7,3]
*/