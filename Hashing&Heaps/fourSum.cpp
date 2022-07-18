#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

// Function to check if four sum exists in an array with the given sum
vector<int> fourSum(int arr[], int n, int sum)
{
  unordered_multimap<int, pair<int, int>> m;
  vector<int> v;

  for (int i = 0; i < n - 1; i++)
  {
    m.insert(make_pair(arr[i] + arr[i + 1], make_pair(i, i + 1)));
  }

  int bre = 0;

  for (auto i = m.begin(); i != m.end(); ++i)
  {
    if (bre == 1)
    {
      break;
    }
    for (auto it = i; it != m.end(); ++it)
    {
      if ((i->first + it->first) == sum)
      {
        v.push_back(i->second.first);
        v.push_back(i->second.second);
        v.push_back(it->second.first);
        v.push_back(it->second.second);
        bre = 1;
        break;
      }
    }
  }
  return v;
}

int main()
{
  int arr[] = {2, 7, 4, 0, 9, 5, 1, 3};
  int sum = 20;

  int n = sizeof(arr) / sizeof(arr[0]);

  vector<int> vec = fourSum(arr, n, sum);

  if (vec.empty())
  {
    cout << "No sum found!";
  }
  else
  {
    for (auto it : vec)
    {
      cout << arr[it] << " ";
    }
  }

  return 0;
}
