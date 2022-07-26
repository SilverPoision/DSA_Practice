#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
  vector<int> arr;

  int top()
  {
    return arr[arr.size() - 1];
  }

  bool isEmpty()
  {
    return (arr.size() == 0);
  }

  int pop()
  {
    arr.pop_back();
    return 1;
  }

  int push(int i)
  {
    arr.push_back(i);
    return i;
  }
  void printStack()
  {
    int it = arr.size() - 1;

    while (it >= 0)
    {
      cout << arr[it] << endl;
      it--;
    }
    cout << endl;
    cout << endl;
  }
};

int main()
{
  Stack *st = new Stack();
  cout << st->isEmpty() << endl;
  st->push(1);
  st->push(2);
  st->push(3);
  st->printStack();
  st->push(4);
  st->push(5);
  st->printStack();
  st->pop();
  st->printStack();
  cout << st->top();

  return 0;
}