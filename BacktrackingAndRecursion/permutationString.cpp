#include <bits/stdc++.h>
using namespace std;

// Function to find all Permutations of a given string str[i..n-1]
// containing all distinct characters
vector<string> ans;
void permutations(string str, int i, int n)
{
  if (i >= n)
  {
    ans.push_back(str);
    return;
  }
  for (int j = i; j < n; j++)
  {
    swap(str[i], str[j]);
    permutations(str, i + 1, n);
  }
}

int main()
{
  string str = "ABC";

  // cout << str.length();

  permutations(str, 0, str.length());
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}
