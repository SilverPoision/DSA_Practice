#include <bits/stdc++.h>
using namespace std;

char keypad[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

void getCount(string n, string out, int index, vector<string> &ans, string map[10])
{
  if (index >= n.length())
  {
    ans.push_back(out);
    return;
  }

  int num = n[index] - '0';
  string val = map[num];

  for (int i = 0; i < val.length(); i++)
  {
    out.push_back(val[i]);
    getCount(n, out, index + 1, ans, map);
    out.pop_back();
  }
}

int main()
{
  vector<string> ans;
  string out;
  int index = 0;
  string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  getCount("6799", out, index, ans, map);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}