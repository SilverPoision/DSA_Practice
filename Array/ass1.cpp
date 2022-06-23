#include <iostream>
using namespace std;

// We rotate an ascending order sorted array at some point unknown
// to user. So for instance, 3 4 5 6 7 might become 5 6 7 3 4.
// Modify binary search algorithm to find an element in the
// rotated array in O(log n) time and O(1) Space complexity

/*solution :
1. take the mid and check that if that is the key
2. if not then check in which grp the mid belongs
to by cheking the mid with start and mid with end
3. After getting the sequence find that in which
sequence the key belongs to and then search in that half
with binary search.
*/

int findTheKey(int arr[], int start, int end, int key)
{

  // checking if the lenght of the arr is 1
  if (start > end)
  {
    return -1;
  }

  int mid = (end + start) / 2;

  // checking if the mid is the key
  if (arr[mid] == key)
  {
    return mid;
  }

  if (arr[mid] >= arr[start])
  {
    if (key >= arr[start] && key <= arr[mid])
    {
      return findTheKey(arr, start, mid - 1, key);
    }
    return findTheKey(arr, mid + 1, end, key);
  }
  if (key >= arr[mid] && key <= arr[end])
  {
    return findTheKey(arr, mid + 1, end, key);
  }
  return findTheKey(arr, start, mid - 1, key);
}

int main()
{
  int arr[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int index = findTheKey(arr, 0, n, 1);
  cout << index << endl;
  return 0;
}