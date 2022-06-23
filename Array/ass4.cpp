#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// We have an array, we have to find an element before which
// all elements are less than it, and after which all are
// greater than it. Finally, return the index of the element,
// if there is no such element, then return -1: Time complexity
// O(n) and Space Complexity O(n)

/*
Solution:
1. Make a arr left and put a min value on arr[o] and
then check for all the indexes in original arr and put the
larget of all the indexes which are left to it.
2. then take a max value in right var and start loop on the arr
and check left[i] < arr[i] && right > arr[i] if yes then resturn i
if not then take the smallest of arr[i] and right;
*/

int findSmallLarger(int arr[], int size)
{
  int left[size];
  left[0] = Integer.MIN_VALUE;

  for (int i = 1; i < size; i++)
  {
    left[i] = Math.max(left[i - 1], arr[i - 1]);
  }

  int right = Integer.MAX_VALUE;

  for (int i = n - 1; i >= 0; i--)
  {
    if (left[i] < arr[i] && right > arr[i])
    {
      return i;
    }
    right = Math.min(right, arr[i]);
  }
  return -1;
}

int main()
{
  int arr[] = {6, 2, 5, 4, 7, 9, 11, 8, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  findSmallLarger(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}