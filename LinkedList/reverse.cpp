#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
  int data;
  struct Node *next;
};

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

void push(struct Node **head, int data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = *head;

  *head = node;
}

struct Node *head = NULL;

Node *reverse(struct Node *head)
{
  Node *prev, *next;

  while (head)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

Node *reverseR(struct Node *node)
{
  if (node->next == NULL)
  {
    head = node;
    return NULL;
  }

  reverseR(node->next);
  Node *temp = node->next;
  temp->next = node;
  node->next = nullptr;
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

  printList(head);

  head = reverseR(head);

  printList(head);

  return 0;
}
