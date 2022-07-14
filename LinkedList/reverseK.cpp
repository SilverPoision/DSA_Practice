#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
  int data;
  Node *next;
};

void insert(Node **head, int new_data);

/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */

Node *reverse(Node *head, int k)
{
  Node *curr = head;
  Node *next = NULL;
  Node *prev = NULL;
  int count = 0;

  while (curr && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if (next != NULL)
  {
    head->next = reverse(next, k);
  }
  return prev;
}

/* Function to Insert a node */
void insert(Node **head, int new_data)
{
  /* allocate node */
  Node *new_node = new Node();

  /* put in the data */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head);

  /* move the head to point to the new node */
  (*head) = new_node;
}

/* Function to print linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
}

int main()
{
  /* Start with the empty list */
  Node *head = NULL;

  /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
  insert(&head, 9);
  insert(&head, 8);
  insert(&head, 7);
  insert(&head, 6);
  insert(&head, 5);
  insert(&head, 4);
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 1);

  cout << "Given linked list \n";
  printList(head);
  head = reverse(head, 3);

  cout << "\nReversed Linked list \n";
  printList(head);

  return (0);
}
