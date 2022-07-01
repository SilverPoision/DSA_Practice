#include <bits/stdc++.h>
using namespace std;

/*
Binary search method to find Median of two sorted Array

Solution :
1. Find the median of both arrays and then check it
m1 < m2 if yes then perform the same steps in the given range.

*/

int median(int arr[], int n)
{
  if (n % 2)
  {
    return arr[n / 2] + arr[n / 2 - 1] / 2;
  }
  else
  {
    return arr[n / 2];
  }
}

int getMedian(int arr1[], int arr2[], int n)
{
  if (n <= 0)
  {
    return n - 1;
  }
  if (n == 1)
  {
    return (arr1[0] + arr2[0]) / 2;
  }
  if (n == 2)
  {
    return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
  }

  int m1 = median(arr1, n);
  int m2 = median(arr2, n);

  if (m1 == m2)
  {
    return m1;
  }

  if (m1 < m2)
  {
    if (n % 2 == 0)
    {
      return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
    }
    else
    {
      return getMedian(arr1, arr2 + n / 2, n - n / 2);
    }
  }

  if (n % 2 == 0)
  {
    return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
  }
  else
  {
    return getMedian(arr2 + n / 2, arr1, n - n / 2);
  }
}

int main()
{
  int array1[] = {1, 6, 8, 10, 12};
  int array2[] = {2, 3, 4, 9, 11};
  int size1 = sizeof(array1) /
              sizeof(array1[0]);
  int size2 = sizeof(array2) /
              sizeof(array2[0]);
  if (size1 == size2)
    cout << "Median is "
         << getMedian(array1, array2, size1);

  return 0;
}

/* Try more Inputs

case1:
 actual = getMedian([0,0],[0,0],2)
 expected = 0

case2:
actual = getMedian([2,7],[11,16],2)
expected = 9

case3:
actual = getMedian([1,2,3,6],[4,6,8,10],4)
expected = 5
*/