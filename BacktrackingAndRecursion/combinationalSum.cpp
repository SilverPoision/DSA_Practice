#include <iostream>
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
void recur(int i, int target, vector<int> n, vector<int> &out)
{
  if (i == (n.size()))
  {
    if (target == 0)
    {
      cout << "[";
      for (auto it : out)
      {
        cout << it << ", ";
      }
      cout << "]";
    }
    return;
  }

  if (target >= n[i])
  {
    out.push_back(n[i]);
    recur(i, (target - n[i]), n, out);
    out.pop_back();
  }

  recur(i + 1, target, n, out);
}

int main()
{

  vector<int> arr{2, 3, 6, 7};
  vector<int> out;

  // recur all combination of numbers from 1 to n having sum n
  recur(0, 7, arr, out);

  return 0;
}