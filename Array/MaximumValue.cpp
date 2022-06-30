#include <bits/stdc++.h>
using namespace std;

/*
Given an array A[] of N positive integers. The task is to find
the maximum of j - i with the constraint of A[i] <= A[j]. Time
Complexity : O(n) Space Complexity : O(n)

Solution:

Make a right array and fill all the values that are greater in right
and then comoare arr[i] to right[j] with i =0 and j = n-1 and make
a maxdiff array and check of its bigger or not then overwrite its value.
*/

int maxDiff(int arr[], int n)
{
  int right[n];
  right[n - 1] = arr[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = max(right[i + 1], arr[i]);
  }
  int i = 0, j = n - 1, maxDiff = -1;

  while (i < n && j >= 0)
  {
    if (right[j] >= arr[i] && maxDiff < (j - i))
    {
      maxDiff = j - i;
    }
    j--;
    i++;
  }
  return maxDiff;
}

int main()
{
  int array[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(array) / sizeof(array[0]);
  cout << "The maximum value of |arr[i] - arr[j]| + |i-j| is " << maxDiff(array, n);
  return 0;
}
/* Try more Inputs
case1:
actual = findDiff([35, 9, 12, 3, 2, 70, 31, 33, 1])
expected = 6

case2:
actual = findDiff([1, 2, 3, 4, 5, 6])
expected = 5

case3:
actual = findDiff([9, 2, 3, 4, 5, 6, 7, 8, 18, 0])
expected = 8

case4:
actual = findDiff([6, 5, 4, 3, 2, 1])
expected = -1

*/