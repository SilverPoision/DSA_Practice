#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
  int data;
  Node *next;
};

/* function prototypes */
Node *SortedMerge(Node *a, Node *b);
void FrontBackSplit(Node *source, Node **a, Node **b);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node **headRef)
{
  Node *head = *headRef;
  if (!head || !head->next)
  {
    return;
  }

  Node *front, *back;
  FrontBackSplit(head, &front, &back);

  MergeSort(&front);
  MergeSort(&back);

  *headRef = SortedMerge(front, back);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node *SortedMerge(Node *a, Node *b)
{
  Node *result = NULL;

  if (a == NULL)
  {
    return b;
  }
  if (b == NULL)
    return a;

  if (a->data <= b->data)
  {
    result = a;
    result->next = SortedMerge(a->next, b);
  }
  else
  {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return result;
}

/* Split the nodes of the given list into front and back halves,
    and return the two lists.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy to find the mid */
void FrontBackSplit(Node *source, Node **a, Node **b)
{
  Node *slow = source;
  Node *fast = source->next;

  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }

  *a = source;
  *b = slow->next;
  slow->next = NULL;
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

/* Function to insert a node at the beginging of the linked list */
void push(Node **head_ptr, int new_data)
{
  /* allocate node */
  Node *new_node = new Node();

  /* put in the data */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ptr);

  /* move the head to point to the new node */
  (*head_ptr) = new_node;
}

int main()
{
  /* Start with the empty list */
  Node *a = NULL;

  /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 14->20->78->98->20->45 */
  push(&a, 14);
  push(&a, 20);
  push(&a, 78);
  push(&a, 98);
  push(&a, 20);
  push(&a, 45);
  /* Sort the above created Linked List */
  MergeSort(&a);

  cout << "Sorted Linked List is: \n";
  printList(a);

  return 0;
}

/* Try more Inputs
Case 1:
Node* res = NULL;
Node* a = NULL;
push(&a, 3);
push(&a, 2);
push(&a, 1);
MergeSort(&a);
printList(a,array);
expected = [1,2,3]

Case 2:
Node* res = NULL;
Node* a = NULL;
push(&a, 1);
MergeSort(&a);
printList(a,array);
expected = [1]
*/