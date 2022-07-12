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
  vector<int> arr;

  if (len % 2 == 0)
  {
    len = (len / 2) - 1;
    while (len >= 0)
    {
      arr.push_back(head->data);
      head = head->next;
      len--;
    }

    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
    {
      // cout << head->data << endl;
      // cout << *it << endl;
      if (head->data != *it)
      {
        return false;
      }
      head = head->next;
    }
  }
  else
  {
    len = (len / 2);
    while (len > 0)
    {
      arr.push_back(head->data);
      head = head->next;
      len--;
    }
    head = head->next;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
    {
      // cout << head->data << endl;
      // cout << *it << endl;
      if (head->data != *it)
      {
        return false;
      }

      head = head->next;
    }
  }
  return true;
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
  one->next = new Node(1);
  one->next->next = new Node(2);
  // one->next->next->next = new Node(2);
  // one->next->next->next->next = new Node(1);

  bool result = isPalindrome(one);

  if (result == true)
    cout << "isPalindromedrome is true\n";
  else
    cout << "isPalindromedrome is false\n";

  return 0;
}