#include <iostream>
using namespace std;

/*
Array consist of only 0's, 1's and 2's. Write an algorithm to
sort  this array in O(n) time complexity and O(1)
Space complexity with only one traversal Asked in

Solution:
1. just put all the 0's in left when you find 0 and swap it with low
and with 2 swap it with high and ignore 1's.
*/

void swap(int *arr, int index1, int index2)
{
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

int *sortOne(int arr[], int size)
{
  int mid = 0, low = 0, high = size - 1;
  while (mid <= high)
  {
    if (arr[mid] == 2)
    {
      swap(arr, mid, high);
      high--;
    }
    else if (arr[mid] == 0)
    {
      swap(arr, low, mid);
      low++;
      mid++;
    }
    else
    {
      mid++;
    }
  }
  return arr;
}

int main()
{
  int arr[] = {1, 2, 0, 2, 2, 1, 1, 0, 0, 1, 1, 2, 2, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *resArr = sortOne(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << resArr[i] << endl;
  }
  return 0;
}