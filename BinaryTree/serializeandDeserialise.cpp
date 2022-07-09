#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MARKER -1

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int key)
  {
    data = key;
    left = right = NULL;
  }
};

void inOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->left);
}

void serialize(Node *root, FILE *fp)
{
  if (root == NULL)
  {
    fprintf(fp, "%d ", MARKER);
    return;
  }
  fprintf(fp, "%d ", root->data);
  serialize(root->left, fp);
  serialize(root->right, fp);
}

void deSerialize(Node *&root, FILE *fp)
{
  int val;

  if (!fscanf(fp, "%d", &val) || val == MARKER)
    return;

  root = new Node(val);
  deSerialize(root->left, fp);
  deSerialize(root->right, fp);
}

int main()
{

  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(4);
  root->left->right = new Node(12);
  root->left->right->left = new Node(10);
  root->left->right->right = new Node(14);

  inOrder(root);

  FILE *fp = fopen("tree.txt", "w");
  if (fp == NULL)
  {
    puts("Could not open file");
    return 0;
  }
  serialize(root, fp);
  fclose(fp);

  Node *root2 = nullptr;
  fp = fopen("tree.txt", "r");
  deSerialize(root2, fp);

  printf("Inorder Traversel ");
  inOrder(root2);

  return 0;
}