#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  int key;
  Node *next;
  Node *prev;

  Node(int key, int value)
  {
    this->key = key;
    this->data = value;
    next = prev = NULL;
  }
};

class LRUCache
{
public:
  int capacity;
  map<int, Node *> Map;
  Node *head = NULL;
  Node *tail = NULL;

  LRUCache(int cap)
  {
    this->capacity = cap;
  }

  void addNode(Node *temp)
  {
    if (head == NULL)
    {
      head = temp;
      tail = head;
    }
    else
    {
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
  }
  void deleteNode(Node *temp)
  {
    if (temp == head)
    {
      head = head->next;
    }
    else if (temp == tail)
    {
      temp->prev = NULL;
    }
    else
    {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
  }

  int get(int key)
  {
    if (Map.find(key) != Map.end())
    {
      Node *res = Map[key];
      Map.erase(key);
      int ans = res->data;
      deleteNode(res);
      addNode(res);
      Map[key] = res;
      cout << "Got the value : " << ans
           << " for the key: " << key << "\n";
      return ans;
    }
    else
    {
      cout << "Did not get any value for the key: "
           << key << "\n";
      return -1;
    }
  }

  void put(int key, int value)
  {
    cout << "Going to set the (key, value) : ("
         << key << ", " << value << ")"
         << "\n";
    if (Map.find(key) != Map.end())
    {
      Node *exist = Map[key];
      Map.erase(key);
      deleteNode(exist);
    }
    if (Map.size() == capacity)
    {
      Map.erase(head->key);
      deleteNode(head);
    }
    Node *newNode = new Node(key, value);
    addNode(newNode);
    Map[key] = newNode;
  }
};

int main()
{
  cout << "Going to test the LRU  "
       << "Cache Implementation\n";

  LRUCache *cache = new LRUCache(2);

  // It will store a key (1) with value
  // 10 in the cache.
  cache->put(1, 10);

  // It will store a key (1) with value 10 in the
  // cache.
  cache->put(2, 20);
  cout << "Value for the key: 1 is "
       << cache->get(1) << "\n"; // returns 10

  // Evicts key 2 and store a key (3) with
  // value 30 in the cache.
  cache->put(3, 30);

  cout << "Value for the key: 2 is "
       << cache->get(2) << "\n"; // returns -1 (not found)

  // Evicts key 1 and store a key (4) with
  // value 40 in the cache.
  cache->put(4, 40);
  cout << "Value for the key: 1 is "
       << cache->get(1) << "\n"; // returns -1 (not found)
  cout << "Value for the key: 3 is "
       << cache->get(3) << "\n"; // returns 30
  cout << "Value for the key: 4 is "
       << cache->get(4) << "\n"; // return 40

  return 0;
}