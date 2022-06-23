// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Write an algorithm to find out next greater number to
// given number with the same set of digits Asked in :

/*
Solution:
1. Check weather which of the pairs from that last has first
smallest no in the left and stop the iteration
2. Then store the index in a min var and the value of the arr[i -2]
in ele var
3. Then start checking the immediat smallest no is the right of the
selected no.
4. Then swap the 2 nos and sort the arr from where you sorted.
*/

int swap(int arr[], int index1, int index2)
{
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

int *findGreatest(int arr[], int n)
{
  int i;
  for (i = n - 1; i > 0; i--)
  {
    if (arr[i] > arr[i - 1])
    {
      break;
    }
  }
  int min = i;
  int ele = arr[i - 1];
  cout << arr[min] << endl;

  for (int j = i + 1; j < n; j++)
  {
    if (arr[j] < arr[min] && arr[j] > ele)
    {
      min = j;
    }
  }

  swap(arr, i - 1, min);
  sort(arr + i, arr + n);
  return arr;
}

int main()
{
  int arr[] = {2, 1, 8, 7, 6, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *res = findGreatest(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << res[i] << endl;
  }
  return 0;
}