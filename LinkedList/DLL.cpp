#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int key)
  {
    this->data = key;
    this->next = NULL;
    this->prev = NULL;
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
      head->prev = nullptr;
      tail->next = nullptr;
    }
    else
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      tail->next = nullptr;
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
  }

  void deleteNode(int key)
  {
    if (!head)
    {
      cout << "List is empty!";
    }
    Node *node = head;
    while (node->next && node->data != key && node != NULL)
    {
      node = node->next;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
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