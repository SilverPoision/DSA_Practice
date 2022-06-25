#include <bits/stdc++.h>
using namespace std;

/*
Array of length n having integers 1 to n with some elements
being repeated. Count frequencies of all elements from 1 to n
in Time Complexity O(n) and Space Complexity O(1) Asked in : :
 PayTm, VmWare, Amazon

 T-Comp: O(nlogn) S-Comp: O(1);
*/

void findfrequency(int arr[], int n)
{
  sort(arr, arr + n);
  int start = 0, end = 0, el;
  for (int i = 0; i < n; i++)
  {
    if (el != arr[i])
    {
      el = arr[i];
      start = i;
    }
    if (arr[i] == arr[i + 1])
    {
      end = i + 1;
    }
    else
    {
      if (start == n - 1)
      {
        cout << "Freq of el " << arr[i] << " is " << 1 << endl;
      }
      else
      {
        cout << "Freq of el " << arr[i] << " is " << end - start + 1 << endl;
        start = i + 1;
        end = 0;
      }
    }
  }
}

int main()
{
  int arr[] = {4, 4, 4, 4};
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