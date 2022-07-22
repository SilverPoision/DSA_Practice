#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
Given a set of array numbers (without duplicates) and a target
number (target), find all unique combinations in the array where
the numbers sum to target. The same repeated number may be chosen
from array unlimited number of times. Note: All numbers (including
target) will be positive integers. The solution set must not
contain duplicate combinations.

*/

// Recursive function to print all combination of numbers
// from i to n having sum n
void recur(int i, int target, vector<int> n, vector<int> &out, vector<vector<int>> &ans)
{

  if (target == 0)
  {
    ans.push_back(out);
    return;
  }

  for (int j = i; j < n.size(); j++)
  {
    if (j > i && n[i] == n[i - 1])
      continue;

    if (target < n[j])
      break;

    out.push_back(n[j]);
    recur(j + 1, (target - n[j]), n, out, ans);
    out.pop_back();
  }
}

int main()
{

  vector<int> arr{10, 1, 2, 7, 6, 1, 5};
  sort(arr.begin(), arr.end());
  vector<int> out;
  vector<vector<int>> ans;
  // map<vector<int>, int> M;

  // recur all combination of numbers from 1 to n having sum n
  recur(0, 8, arr, out, ans);

  // for (auto it : ans)
  // {
  //   sort(it.begin(), it.end());
  //   M[it] = 0;
  // }

  // for (auto it : M)
  // {
  //   cout << "[";
  //   for (auto it2 : it.first)
  //   {
  //     cout << it2 << ", ";
  //   }
  //   cout << "]";
  // }

  for (auto it : ans)
  {
    cout << "[";
    for (auto it2 : it)
    {
      cout << it2 << ", ";
    }
    cout << "]";
  }

  return 0;
}