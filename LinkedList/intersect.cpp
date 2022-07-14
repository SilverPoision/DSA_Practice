#include <bits/stdc++.h>
using namespace std;

/*
Write a program to find the node at which the intersection of two
singly linked lists begins.

*/

/* Link list node */
class Node
{
public:
  int data;
  Node *next;
};

int getSize(Node *head)
{
  if (head == NULL)
  {
    return -1;
  }
  int count = 0;
  while (head)
  {
    head = head->next;
    count++;
  }
  return count;
}

int findIntesectionNode(Node *head1, Node *head2)
{
  int size1 = getSize(head1);
  int size2 = getSize(head2);

  int diff = abs(size1 - size2);

  if (size1 > size2)
  {
    while (diff >= 1)
    {
      head1 = head1->next;
      diff--;
    }
  }
  else
  {

    while (diff >= 1)
    {
      head2 = head2->next;
      diff--;
    }
  }

  while (head1 && head2)
  {
    if (head1->data == head2->data)
    {
      return head1->data;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
  return -1;
}

int main()
{
  /*
      Create two linked lists

      1st 3->6->9->15->30
      2nd 10->15->30

      15 is the intersection point
  */

  Node *newNode;

  // Addition of new nodes
  Node *head1 = new Node();
  head1->data = 10;

  Node *head2 = new Node();
  head2->data = 3;

  newNode = new Node();
  newNode->data = 6;
  head2->next = newNode;

  newNode = new Node();
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = new Node();
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next = newNode;

  newNode = new Node();
  newNode->data = 30;
  head1->next->next = newNode;

  head1->next->next->next = NULL;

  cout << "The node of intersection is " << findIntesectionNode(head1, head2);
}

/*

    test_getIntersectionNode1():
      headA = ListNode(4)
      headB = ListNode(5)
      headA.next = ListNode(7)
      headA.next.next = ListNode(9)
      headB.next = ListNode(7)

      ob1 = new Main()
      actual = ob1.findIntersection(headA, headB)
      expected = 7


    test_getIntersectionNode2():
      headA = ListNode(4)
      headB = ListNode(5)
      headA.next = ListNode(7)
      headA.next.next = ListNode(9)
      headB.next = ListNode(17)
      headB.next.next = ListNode(18)

      ob1 = new Main()
      actual = ob1.findIntersection(headA, headB)
      expected = -1

*/