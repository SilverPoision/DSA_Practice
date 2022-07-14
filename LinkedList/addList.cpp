#include <bits/stdc++.h>
using namespace std;

/*
Given two numbers represented by two linked lists, write a function
that returns the sum list. The sum list is linked list representation
of the addition of two input numbers. It is not allowed to modify
the lists. Also, not allowed to use explicit extra space

Solution:
https://www.geeksforgeeks.org/sum-of-two-linked-lists/

*/

// A linked List Node
class Node
{
public:
  int data;
  Node *next;
};

typedef Node node;

/*function to insert
a node at the beginning of linked list */
void insert(Node **head_ref, int new_data)
{
  /* allocate node */
  Node *new_node = new Node[(sizeof(Node))];

  /* put in the data */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

void swapPointer(Node **a, Node **b)
{
  node *t = *a;
  *a = *b;
  *b = t;
}

void addLinkedList(Node *head1, Node *head2, Node **result, int *carry)
{
  if (!head1)
    return;

  addLinkedList(head1->next, head2->next, result, carry);

  int sum = head1->data + head2->data + (*carry);
  *carry = sum / 10;
  insert(result, (sum % 10));
}

int getSize(Node *head)
{
  int size = 0;
  while (head != NULL)
  {
    head = head->next;
    size++;
  }
  return size;
}

void addLinkedListOdd(Node *head1, Node *cur, Node **result, int *carry)
{
  int sum;

  if (head1 != cur)
  {
    addLinkedListOdd(head1->next, cur, result, carry);

    sum = head1->data + (*carry);
    *carry = sum / 10;
    insert(result, (sum % 10));
  }
}

void addLinkedListUtil(Node *head1, Node *head2, Node **result)
{
  Node *cur;

  if (head1 == NULL)
  {
    *result = head2;
    return;
  }
  else if (head2 == NULL)
  {
    *result = head1;
    return;
  }

  int size1 = getSize(head1);
  int size2 = getSize(head2);
  int carry = 0;

  if (size1 == size2)
  {
    addLinkedList(head1, head2, result, &carry);
  }
  else
  {
    int diff = abs(size1 - size2);

    if (size1 < size2)
    {
      swapPointer(&head1, &head2);
    }

    for (cur = head1; diff--; cur = cur->next)
      ;

    addLinkedList(cur, head2, result, &carry);

    addLinkedListOdd(head1, cur, result, &carry);
  }
  if (carry > 0)
  {
    insert(result, carry);
  }
}

int main()
{
  Node *head1 = NULL, *head2 = NULL, *result = NULL;

  int arr1[] = {9, 9, 9};
  int arr2[] = {1, 8};

  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  // Create first list as 9->9->9
  int i;
  for (i = size1 - 1; i >= 0; --i)
    insert(&head1, arr1[i]);

  // Create second list as 1->8
  for (i = size2 - 1; i >= 0; --i)
    insert(&head2, arr2[i]);

  addLinkedListUtil(head1, head2, &result);

  printList(result);

  return 0;
}
