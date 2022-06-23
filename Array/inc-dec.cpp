#include <iostream>
using namespace std;

// One array of integers is given as an input ,which is
// initially increasing and then decreasing or it can be
// only increasing or decreasing , you need to find the
// maximum value in the array in O(Log n) Time complexity
// and O(1) Space Complexity Asked in :

/*
Solution:
1. Take the mid of the array and then check of the left is less
and right is more if yes then return yes
2. If not then check if the mid is less in right and more in left
and then make the low mid+1 and high as same.
3. else make low as low and high as mid-1
*/

int findMax(int arr[], int low, int high)
{
  if (low == high)
  {
    return low;
  }

  if (low + 1 == high)
  {
    if (arr[low] > arr[high])
    {
      return low;
    }
    else
    {
      return high;
    }
  }

  int mid = ((high + low) / 2);

  if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
  {
    return mid;
  }
  else if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
  {
    return findMax(arr, mid + 1, high);
  }
  else
  {
    return findMax(arr, low, mid - 1);
  }
}

int main()
{
  int arr[] = {6, 9, 15, 25, 35, 50, 77, 41, 29, 23, 8};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int max = findMax(arr, 0, arr_size);
  cout << max << endl;
  return 0;
}