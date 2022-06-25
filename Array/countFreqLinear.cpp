#include <bits/stdc++.h>
using namespace std;

/*
Array of length n having integers 1 to n with some elements
being repeated. Count frequencies of all elements from 1 to n
in Time Complexity O(n) and Space Complexity O(1) Asked in : :
 PayTm, VmWare, Amazon

Solution:
1.Check if the array largest ele is greater than n-1
if yes the subtract all ele by 1 or by the diff in max ele and n
2. Run a loop and check  if (arr[i] >= n)
    {
      int ele = arr[i] % n;
      arr[ele] = arr[ele] + n; updating index
    }
    else
    {
      arr[arr[i]] = arr[arr[i]] + n; updating index
    }
3. Print the arr.

 T-Comp: O(N) S-Comp: O(1);
*/

void findfrequency(int arr[], int n)
{
  bool big = false;
  if (*max_element(arr, arr + n) > n - 1)
  {
    big = true;
    for (int i = 0; i < n; i++)
    {
      arr[i]--;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= n)
    {
      int ele = arr[i] % n;
      arr[ele] = arr[ele] + n;
    }
    else
    {
      arr[arr[i]] = arr[arr[i]] + n;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (big)
    {
      if (arr[i] >= n)
      {
        cout << i + 1 << ": " << arr[i] / n << endl;
      }
    }
    else
    {
      if (arr[i] >= n)
      {
        cout << i << ": " << arr[i] / n << endl;
      }
    }
  }
}

int main()
{
  int arr[] = {5, 2, 7, 7, 5, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  findfrequency(arr, n);
  return 0;
}

/* Try more Inputs
case 1:
actual = countfrequenciesEfficient([1, 2, 2, 1, 1, 2, 3, 2])
expected = [[1 3],[2 4],[3  1]]

case2:
 actual = countfrequenciesEfficient([1, 2, 2])
 expected = [[1 1],[2 2]]

case3:
actual = countfrequenciesEfficient([4, 4, 4, 4}])
expected = [[4 4]]
*/