#include <bits/stdc++.h>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
  int data;
  struct Node *next;
};

// Helper function to print given linked list
void printList(struct Node *head)
{
  struct Node *ptr = head;
  while (ptr)
  {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
  }

  printf("null\n");
}

// Helper function to insert a new Node in the beginning of the linked list
void push(struct Node **head, int data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = *head;

  *head = node;
}

// Iterative function to reverse nodes of linked list
void reverse(Node **head)
{
  // Initialize prev and current pointers
  Node *prev = NULL, *curr = *head, *next;

  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

// Recursive function to construct a linked list by merging
// alternate nodes of two given linked lists
// Note in video we dicussed iterative approch to merge Linked List, this is another recursion approch to merge
struct Node *mergeLinkedList(struct Node *a, struct Node *b)
{
  // see if either list is empty
  if (a == NULL)
    return b;

  if (b == NULL)
    return a;

  // it turns out to be convenient to do the recursive call first --
  // otherwise a->next and b->next need temporary storage

  struct Node *recur = mergeLinkedList(a->next, b->next);

  struct Node *result = a; // one node from a
  a->next = b;             // one from b
  b->next = recur;         // then the rest

  return result;
}

// Function to split the linked list into two equal parts and return
// pointer to the second half
Node *findMiddle(struct Node *head)
{
  struct Node *prev = NULL;
  struct Node *slow = head, *fast = head;

  // find middle pointer
  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // for odd nodes, fix middle
  if (fast && fast->next == NULL)
  {
    prev = slow;
    slow = slow->next;
  }

  // make next of prev node null
  prev->next = NULL;

  // return mid node
  return slow;
}

// Function to rearrange given linked list in specific way
void rearrange(struct Node *head)
{
  if (!head)
    return;

  Node *mid = findMiddle(head);
  reverse(&mid);

  mergeLinkedList(head, mid);
}

// main method
int main(void)
{
  // input keys
  int keys[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(keys) / sizeof(keys[0]);

  struct Node *head = NULL;
  for (int i = n - 1; i >= 0; i--)
    push(&head, keys[i]);

  rearrange(head);
  printList(head);

  return 0;
}

/* Try more Inputs
Case 1:
        int[] keys = { 1,2,3 };
        ArrayList<Integer> mlist = new ArrayList<Integer>();
        Node head = null;
        for (int i = keys.length - 1; i >= 0; i--) {
            head = new Node(keys[i], head);
        }

        rearrange(head);
        printList(head,mlist);
        System.out.print(mlist);
        expected = [3,1,2]

Case 1:
        int[] keys = { 1,2,3,4,5 };
        ArrayList<Integer> mlist = new ArrayList<Integer>();
        Node head = null;
        for (int i = keys.length - 1; i >= 0; i--) {
            head = new Node(keys[i], head);
        }

        rearrange(head);
        printList(head,mlist);
        System.out.print(mlist);
        expected = [1,5,2,4,3]
*/
