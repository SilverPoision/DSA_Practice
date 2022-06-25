#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> g1(10, 1);
  // g1.push_back(1);
  for (auto i = g1.begin(); i != g1.end(); i++)
  {
    cout << *i << endl;
  }
  for (auto it : g1)
  {
    cout << it << endl;
  }

  for (auto it = 0; it < 10; it++)
  {
    cout << g1[it] << endl;
  }
  return 0;
}