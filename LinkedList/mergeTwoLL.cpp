/* C++ program to merge two sorted linked lists */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
  int data;
  Node *next;
};

void push(Node **head_ref, int new_data)
{
  /* allocate node */
  Node *new_node = new Node();

  /* put in the data */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

/* pull off the front node of
the source and put it in dest */
void MoveNode(Node **destRef, Node **sourceRef);

/* Takes two lists sorted in increasing
order, and splices their nodes together
to make one big sorted list which
is returned. */
Node *SortedMerge(Node *a, Node *b)
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
    a = temp->next;
  }
  else
  {
    temp = b;
    b = temp->next;
  }

  newList = temp;

  while (a && b)
  {
    if (a->data <= b->data)
    {
      temp->next = a;
      temp = a;
      a = temp->next;
    }
    else
    {
      temp->next = b;
      temp = b;
      b = temp->next;
    }
  }

  if (a == NULL)
  {
    temp->next = b;
  }
  if (b == NULL)
  {
    temp->next = a;
  }
  return newList;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
}

/* Driver code*/
int main()
{
  /* Start with the empty list */
  Node *res = NULL;
  Node *a = NULL;
  Node *b = NULL;

  /* Let us create two sorted linked lists
  to test the functions
  Created lists, a: 5->10->15, b: 2->3->20 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  /* Remove duplicates from linked list */
  res = SortedMerge(a, b);

  cout << "Merged Linked List is: \n";
  printList(res);

  return 0;
}

// This code is contributed by rathbhupendra
