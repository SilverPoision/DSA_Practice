#include <iostream>
using namespace std;

// You have an array of non-negative integers,you are initially
// positioned at the first index of the array.Each element in
// the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index in O(n)
// Time complexity and O(1) Space Complexity Asked in :

/*
Solution:
1. Take 3 ints a b and jump and put the value of arr[0]
in and b and jump =1
2. decrement a and b on every step forward
3. if a[i] > b then b = a[i] and if a = 0; a = b and jump++;
*/

int jumpGame(int arr[], int size)
{
  int a = arr[0];
  int b = arr[0];
  int jump = 1;

  for (int i = 1; i < size; i++)
  {
    if (i > size - 1)
    {
      return jump;
    }
    a--;
    b--;
    if (arr[i] > b)
    {
      b = arr[i];
    }
    if (a == 0)
    {
      jump++;
      a = b;
    }
  }
  return jump;
}

int main()
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int jump = jumpGame(arr, n);
  cout << jump << endl;
  return 0;
}