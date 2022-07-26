#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
  stack<int> stack;
  int minValue;

  void getMin()
  {
    if (stack.empty())
      cout << "Stack is empty\n";
    else
      cout << "Minimum Element in the stack is: "
           << minValue << "\n";
  }

  void peek()
  {
    if (stack.empty())
    {
      cout << -1 << endl;
      return;
    }

    int t = stack.top();

    if (t < minValue)
    {
      cout << minValue;
    }
    else
    {
      cout << t;
    }
  }

  // Remove the top element from Stack
  void pop()
  {
    if (stack.empty())
    {
      cout << -1 << endl;
      return;
    }

    int t = stack.top();
    stack.pop();

    if (t < minValue)
    {
      cout << minValue << endl;
      minValue = 2 * minValue - t;
    }
    else
    {
      cout << t << endl;
    }
  }

  // Removes top element from MyStack
  void push(int x)
  {
    if (stack.empty())
    {
      minValue = x;
      stack.push(x);
      cout << "Number Inserted: " << x << "\n";
      return;
    }

    else if (x < minValue)
    {
      stack.push(2 * x - minValue);
      minValue = x;
    }
    else
    {
      stack.push(x);
    }

    cout << "Number Inserted: " << x << "\n";
  }
};

int main()
{
  MyStack stack;
  stack.push(3);
  stack.push(5);
  stack.getMin();
  stack.push(2);
  stack.push(1);
  stack.getMin();
  stack.pop();
  stack.getMin();
  stack.pop();
  stack.peek();

  return 0;
}

/* Try more Inputs
Case 1:
MyStack stack;
stack.push(13);
stack.push(5);
int result = s.getMin();
expected = 5
Case 2:
MyStack stack;
stack.push(-1);
stack.push(2);
int result = s.getMin();
expected = -1
*/