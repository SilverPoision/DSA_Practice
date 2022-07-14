#include <bits/stdc++.h>
using namespace std;

/*
Linked list is given also, in addition to the next reference, each
node has a child pointer that can point to a separate list. With
the head node, flatten the list to a single-level linked list in
Time Complexity O(n) Asked in : Linkedin, Yahoo, Microsoft

Solution
*/

class Node
{
public:
  int data;
  Node *right;
  Node *down;
};

/* Function to insert the node at the beginning */
void push(Node **headPtr, int new_data)
{
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->right = nullptr;
  new_node->down = (*headPtr);
  (*headPtr) = new_node;
}

/* Function to print nodes in the flattened linked list */
void printList(Node *node)
{
  while (node)
  {
    cout << node->data << " ";

    Node *temp = node->down;
    while (temp)
    {
      cout << temp->data << " ";
      temp = temp->down;
    }

    node = node->right;
  }
}

void printList1(Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->down;
  }
}

// function to merge two sorted linked lists
Node *merge(Node *a, Node *b)
{
  Node *newList = nullptr;
  Node *temp;

  if (a == NULL)
  {
    return b;
  }
  if (b == NULL)
  {
    return a;
  }

  if (a->data <= b->data)
  {
    temp = a;
    a = temp->down;
  }
  else
  {
    temp = b;
    b = temp->down;
  }

  newList = temp;

  while (a && b)
  {
    if (a->data <= b->data)
    {
      temp->down = a;
      temp = a;
      a = temp->down;
    }
    else
    {
      temp->down = b;
      temp = b;
      b = temp->down;
    }
  }

  if (a == NULL)
  {
    temp->down = b;
  }
  if (b == NULL)
  {
    temp->down = a;
  }
  return newList;
}

// Main function that flattens a given linked list
Node *flatten(Node *root)
{
  if (!root || !root->right)
  {
    return root;
  }
  Node *newList = root;

  while (root->right)
  {
    newList = merge(newList, root->right);
    root = root->right;
  }
  return newList;
}

int main()
{
  Node *root = NULL;

  /* Let us create the following linked list
     5 -> 10 -> 19 -> 28
     |    |     |     |
     V    V     V     V
     7    20    22    35
     |          |     |
     V          V     V
     8          50    40
     |                |
     V                V
     30               45
  */
  push(&root, 30);
  push(&root, 8);
  push(&root, 7);
  push(&root, 5);

  push(&(root->right), 20);
  push(&(root->right), 10);

  push(&(root->right->right), 50);
  push(&(root->right->right), 22);
  push(&(root->right->right), 19);

  push(&(root->right->right->right), 45);
  push(&(root->right->right->right), 40);
  push(&(root->right->right->right), 35);
  push(&(root->right->right->right), 28);

  // Let us flatten the list
  root = flatten(root);

  // Let us print the flatened linked list
  printList1(root);

  return 0;
}
