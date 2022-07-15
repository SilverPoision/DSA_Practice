#include <bits/stdc++.h>
using namespace std;

/*
Check Single Linked List is Palindrome or not

Solution ;
This can also be solved by revresing the seconf half and then compare it.
*/

struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

Node *reverse(Node *head)
{
  if (head == NULL)
  {
    return nullptr;
  }

  Node *next = nullptr, *prev = nullptr;

  while (head)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  return prev;
}

int findLength(Node *head);

// Function to check if the linked list
// is palindrome or not
bool isPalindrome(Node *head)
{
  int len = findLength(head);
  if (len == 1)
  {
    return true;
  }

  Node *temp = head;
  len = len / 2;

  while (len > 0)
  {
    temp = temp->next;
    len--;
  }

  temp = reverse(temp);

  while (temp && head)
  {
    if (head->data == temp->data)
    {
      temp = temp->next;
      head = head->next;
    }
    else
    {
      return false;
    }
  }

  if (head == NULL && temp == NULL)
    return true;
  return false;
}

int findLength(Node *head)
{
  int length = 0;

  while (head != NULL)
  {
    length++;
    head = head->next;
  }
  return length;
}

int main()
{

  // Addition of linked list
  Node *one = new Node(1);
  one->next = new Node(3);
  one->next->next = new Node(2);
  one->next->next->next = new Node(2);
  one->next->next->next->next = new Node(1);

  bool result = isPalindrome(one);

  if (result == true)
    cout << "isPalindromedrome is true\n";
  else
    cout << "isPalindromedrome is false\n";

  return 0;
}