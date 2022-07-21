#include <bits/stdc++.h>
using namespace std;

/*
Given n pairs of parentheses, write a function to generate all
combinations of well-formed parentheses.
*/

void printParenthesesPairs(int n, int open, int close, vector<string> &ans, string str)
{
  if (open == n && close == n)
  {
    ans.push_back(str);
  }

  if (open < n)
  {
    printParenthesesPairs(n, open + 1, close, ans, str + "(");
  }
  if (close < open)
  {
    printParenthesesPairs(n, open, close + 1, ans, str + ")");
  }
}
int main()
{
  int n = 4;
  vector<string> ans;
  cout << "All parentheses pairs of length " << n << " are:\n";
  if (n > 0)
    printParenthesesPairs(n, 0, 0, ans, "");

  for (auto it : ans)
  {
    cout << "[ ";

    cout << it;

    cout << " ]";
  }
  return 0;
}

/*
  test_validParenthesis_1():
        n = 3;
        str = [""] * 2 * n;
        actual = printParenthesis(str,n)
        expected = ["((()))","(()())", "(())()", "()(())", "()()()"]
        self.assertEqual(actual, expected)

     test_validParenthesis_2():
        n = 2;
        str = [""] * 2 * n;
        actual = printParenthesis(str,n)
        expected = ["(())","()()"]
        self.assertEqual(actual, expected)
*/