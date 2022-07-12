#include <bits/stdc++.h>
using namespace std;

/*
Given a Linked List and a number n, write a function that returns
the value at the n’th node from the end of the Linked List.

The solution just use an array and store all the keys in tothe arr
and take the lenghthof the array and just gets the last n th key as answer.

thi can also be solved by taking the length in consideration.
or by using 2 pointers approch.
*/

/* Link list node */
struct Node
{
  int data;
  struct Node *next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLastUtil(struct Node *head, vector<int> &arr)
{
  if (head == NULL)
  {
    return;
  }

  arr.push_back(head->data);
  if (head->next)
  {
    printNthFromLastUtil(head->next, arr);
  }
  else
    return;
}

void printNthFromLast(struct Node *head, int n)
{
  vector<int> arr;
  printNthFromLastUtil(head, arr);

  cout << arr[n - 1] << endl;
}

void insert(struct Node **head_ptr, int new_data)
{
  struct Node *new_node = new Node();

  new_node->data = new_data;

  new_node->next = (*head_ptr);

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
  insert(&head, 9);

  printNthFromLast(head, 4);
  return 0;
}