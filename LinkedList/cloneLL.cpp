#include <bits/stdc++.h>
using namespace std;

/*
You are given a double Link List with one reference of each node
pointing to the next node just like in a single link list.
The second reference however can point to any node in the list
and not just the previous node.Write a program in O(n) time which
will create a copy of this list Asked in : Myntra, Expdia, Microsoft, J P Morgan

Solution:
1. Make a hashMap and put all the new nodes in the map and then
    again set the curr to start
2. Then set map[curr]->next = map[curr->next]
3. Then set map[curr]->random = map[curr->random]
*/

// Structure of linked list Node
struct Node
{
  int data;
  Node *next, *random;
  Node(int x)
  {
    data = x;
    next = random = NULL;
  }
};

// Utility function to print the list.
void print(Node *start)
{
  while (start)
  {
    cout << start->data << " ";
    cout << start->random->data << " ";
    if (start->next)
    {
      start = start->next;
    }
    else
    {
      start = NULL;
    }
  }
}

// This function clones a given linked list

Node *clone(Node *start)
{
  Node *curr = start, *copy;
  map<Node *, Node *> m;
  m[NULL] = NULL;

  while (curr)
  {
    copy = new Node(curr->data);
    m[curr] = copy;
    curr = curr->next;
  }

  curr = start;

  while (curr)
  {
    m[curr]->next = m[curr->next];
    m[curr]->random = m[curr->random];
    curr = curr->next;
  }

  return m[start];
}

// Driver code
int main()
{
  Node *start = new Node(3);
  start->next = new Node(4);
  start->next->next = new Node(5);
  start->next->next->next = new Node(6);
  start->next->next->next->next = new Node(7);

  // 3's random points to 5
  start->random = start->next->next;

  // 4's random points to 2
  start->next->random = start;

  // 5's and 6's random points to 7
  start->next->next->random =
      start->next->next->next->next;
  start->next->next->next->random =
      start->next->next->next->next;

  // 7's random points to 4
  start->next->next->next->next->random =
      start->next;

  cout << "Original list : \n";
  print(start);

  cout << "\nCloned list : \n";
  Node *cloned_list = clone(start);
  print(cloned_list);

  return 0;
}
