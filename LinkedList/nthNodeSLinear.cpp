#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node
{
  int data;
  struct Node *next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n, Node **ptr)
{
  if (head == NULL)
  {
    return;
  }
  if (n < 1)
  {
    *ptr = (*ptr)->next;
  }
  printNthFromLast(head->next, n - 1, ptr);
}

void insert(struct Node **head_ptr, int new_data)
{
  /* allocate node */
  struct Node *new_node = new Node();

  /* put in the data */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ptr);

  /* move the head to point to the new node */
  (*head_ptr) = new_node;
}

int main()
{

  struct Node *head = NULL;

  // create linked 35->15->4->20
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);
  insert(&head, 6);
  insert(&head, 7);
  insert(&head, 8);

  Node *ptr = head;
  printNthFromLast(head, 4, &ptr);
  cout << ptr->data << endl;
  return 0;
}