#include <bits/stdc++.h>
using namespace std;

void reverseWords(string s)
{
  stack<string> st;
  string str;
  for (int i = 0; i <= s.length(); i++)
  {
    if (s[i] == ' ' || i == s.length())
    {
      // cout << str << " " << endl;

      st.push(str);
      str = "";
      continue;
    }

    str += s[i];
    // cout << str;
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}

int main()
{
  string s = "i like this program very much";
  reverseWords(s);
  return 0;
}