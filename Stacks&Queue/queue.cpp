#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
  vector<int> arr;

  int front()
  {
    return arr[0];
  }

  bool isEmpty()
  {
    return (arr.size() == 0);
  }

  int pop()
  {
    arr.erase(arr.begin());
    return 1;
  }

  int push(int i)
  {
    arr.push_back(i);
    return i;
  }
  void printStack()
  {
    for (auto it : arr)
    {
      cout << it << endl;
    }
    cout << endl;
    cout << endl;
  }
};

int main()
{
  Queue *que = new Queue();
  cout << que->isEmpty() << endl;
  que->push(1);
  que->push(2);
  que->push(3);
  que->printStack();
  que->push(4);
  que->push(5);
  que->printStack();
  que->pop();
  cout << que->isEmpty() << endl;

  que->printStack();
  cout << que->front();

  return 0;
}