#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int key)
  {
    this->data = key;
    this->next = NULL;
  }
};

class LinkedList
{
public:
  Node *head = NULL;
  Node *tail = NULL;

  void insert(int data)
  {
    Node *newNode = new Node(data);

    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void traverse()
  {
    if (!head)
    {
      cout << "List is empty!";
    }
    Node *node = head;
    while (node != nullptr)
    {
      cout << node->data << " ";
      node = node->next;
    }
    cout << endl;
  }

  void search(int key)
  {
    if (!head)
    {
      cout << "List is empty!";
    }
    Node *node = head;
    while (node->data != key && node != NULL)
    {
      node = node->next;
    }
    cout << node->data << " ";
  }

  void deleteNode(int key)
  {
    if (!head)
    {
      cout << "List is empty!";
    }
    Node *node = head;
    Node *prev = nullptr;
    while (node->next && node->data != key && node != NULL)
    {
      prev = node;
      node = node->next;
    }
    if (prev->next->data == key)
    {
      prev->next = node->next;
    }
  }
};

int main()
{
  LinkedList *node = new LinkedList();
  node->insert(1);
  node->insert(10);
  node->insert(20);
  node->insert(30);
  node->traverse();
  node->deleteNode(10);
  node->traverse();
  return 0;
}