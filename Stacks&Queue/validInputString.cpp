#include <bits/stdc++.h>
using namespace std;

bool areParanthesisBalanced(string expr)
{

  if (expr.length() % 2 != 0)
  {
    return false;
  }
  stack<char> s;

  for (int i = 0; i < expr.length(); i++)
  {
    if (expr[i] == '{')
    {
      s.push('}');
    }
    else if (expr[i] == '[')
    {
      s.push(']');
    }
    else if (expr[i] == '(')
    {
      s.push(')');
    }
    else if (s.top() == expr[i])
    {
      s.pop();
    }
    else if (s.top() != expr[i])
    {
      return false;
    }
  }
  return s.empty();
}

int main()
{
  string expr = "{()}[]";

  if (areParanthesisBalanced(expr))
    cout << "Balanced";
  else
    cout << "Not Balanced";
  return 0;
}