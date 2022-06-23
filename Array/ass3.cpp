#include <iostream>
using namespace std;

// Given a sorted array, remove the duplicates in place such
// that each element appear only once and return the new length.
// Do not allocate extra space for another array, Time complexity
// O(n) and Space complexity O(1)

/*
Solution:
1. Declare 2 vars i and j and run a loop on arr
2. check if the i and i+1 value are diff and if they are
update the arr[j] = arr[i] and increase the j
3. If arr[i] == arr[i+1] then do nothing.
4. Copy the last item to the arr[j] value.
*/

int *removeDups(int arr[], int size)
{
  int i;
  int j = 0;

  for (int i = 0; i < size; i++)
  {
    if (arr[i] != arr[i + 1])
    {
      arr[j] = arr[i];
      j++;
    }
  }
  arr[j] = arr[size - 1];
  j++;
  return arr;
}

int main()
{
  int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *resArr = removeDups(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << resArr[i] << endl;
  }
  return 0;
}