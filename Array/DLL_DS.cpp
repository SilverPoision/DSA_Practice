#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */

class myStack
{
  struct Node
  {
    int num;
    Node *next;
    Node *prev;

    Node(int num) { this->num = num; }
  };

  Node *head = NULL;
  Node *mid = NULL;
  int size = 0;

public:
  void push(int data)
  {
    size++;
    Node *temp = new Node(data);
    if (head == NULL)
    {
      head = temp;
      mid = temp;
      return;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
    if (size % 2 == 0)
    {
      mid = mid->prev;
    }
  }
  int pop()
  {
    int data = -1;
    if (size != 0)
    {
      data = head->num;
      if (size == 1)
      {
        head = NULL;
        mid = NULL;
      }
      else
      {
        head = head->next;
        head->prev = NULL;
        if (size % 2 == 0)
        {
          mid = mid->next;
        }
      }
      size--;
    }
    return data;
  }

  int findMiddle()
  {
    if (size == 0)
    {
      return -1;
    }

    return mid->num;
  }

  void deleteMiddle()
  {
    if (size != 0)
    {
      if (size == 1)
      {
        head = NULL;
        mid = NULL;
      }
      else if (size == 2)
      {
        head = head->prev;
        mid = mid->prev;
        head->next = NULL;
      }
      else
      {
        mid->next->prev = mid->prev;
        mid->prev->next = mid->next;
        if (size % 2 == 0)
        {
          mid = mid->next;
        }
        else
        {
          mid = mid->prev;
        }
      }
    }
    size--;
  }
};

/* Representation of the stack data structure
that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to
middle node and count of nodes */

int main()
{
  /* Let us create a stack using insert() operation*/
  myStack st;
  st.push(11);
  st.push(22);
  st.push(33);
  st.push(44);
  st.push(55);
  st.push(66);
  st.push(77);
  st.push(88);
  st.push(99);
  cout << "Popped : " << st.pop() << endl;
  cout << "Popped : " << st.pop() << endl;
  cout << "Middle Element : " << st.findMiddle() << endl;
  st.deleteMiddle();
  cout << "New Middle Element : " << st.findMiddle() << endl;
  return 0;
}