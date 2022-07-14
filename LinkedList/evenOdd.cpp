#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void segregateEvenOdd(Node **head)
{
  Node *temp = *head;
  Node *even = NULL;
  Node *evenEnd = NULL;
  Node *odd = NULL;
  Node *oddEnd = NULL;

  while (temp != NULL)
  {
    if (temp->data % 2 == 0)
    {
      if (even == NULL)
      {
        even = temp;
        evenEnd = even;
      }
      else
      {
        evenEnd->next = temp;
        evenEnd = evenEnd->next;
      }
    }
    else
    {
      if (odd == NULL)
      {
        odd = temp;
        oddEnd = odd;
      }
      else
      {
        oddEnd->next = temp;
        oddEnd = oddEnd->next;
      }
    }
    temp = temp->next;
  }

  if (odd == NULL || even == NULL)
  {
    return;
  }

  evenEnd->next = odd;
  oddEnd->next = NULL;
  *head = even;
}

/* Function to insert a node at the beginning */
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

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

int main()
{
  /* Start with the empty list */
  Node *head = NULL;

  /* Let us create a sample linked list as following
  0->2->4->6->8->10->11 */

  insert(&head, 11);
  insert(&head, 10);
  insert(&head, 9);
  insert(&head, 6);
  insert(&head, 4);
  insert(&head, 1);
  insert(&head, 0);

  cout << "Original Linked list ";
  printList(head);

  segregateEvenOdd(&head);

  cout << "\nModified Linked list ";
  printList(head);

  return 0;
}
