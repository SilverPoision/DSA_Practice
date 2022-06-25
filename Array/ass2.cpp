#include <iostream>
using namespace std;

// Given an array nums, write a function to move all 0's to the
// end of it while maintaining the relative order of the non-zero
//  elements in O(n) Time complexity and O(1) Space complexity
//  with single traversal allowed

/*
Solution:
1. get two var on frsrt index i and cnt
2. Check if the i index is a non zero value
if it is then update the value with
arr[ctn] = arr[i]; and then increase the counter
3. If the arr[i] is a zero then just ignore and increase the i
4. After the loop finishes just update all the indexes after
ctn with 0.
*/

int *sortZerosMy(int arr[], int size)
{
  int low = -1, mid = 0, high = size - 1;

  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      if (low < 0)
      {
        low = mid;
        mid++;
        continue;
      }
      mid++;
    }
    else
    {
      if (low >= 0)
      {
        arr[low] = arr[mid];
        mid++;
        low++;
        continue;
      }
      mid++;
    }
  }
  while (low < size)
  {
    arr[low++] = 0;
  }
  return arr;
}

int *sortZeros(int arr[], int n)
{
  int ctn = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      arr[ctn++] = arr[i];
    }
  }

  while (ctn < n)
  {
    arr[ctn++] = 0;
  }
  return arr;
}

int main()
{
  int arr[] = {1, 3, 0, 2, 4, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *resArr = sortZerosMy(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << resArr[i] << endl;
  }
  return 0;
}

// if (arr[mid] != 0)
//     {
//       if (low < 0)
//       {
//         mid++;
//       }
//       else
//       {
//         swap(arr, low, mid);
//         low++;
//         mid++;
//       }
//     }
//     else
//     {
//       low = mid;
//       mid++;
//     }