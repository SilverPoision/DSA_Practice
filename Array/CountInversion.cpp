#include <iostream>
using namespace std;

int mergeSort(int arr[], int res[], int low, int high);

int merge(int arr[], int res[], int low, int high, int mid)
{
  int i = low, k = low, j = mid;
  int inversionCount = 0;

  while (i <= mid - 1 && j <= high)
  {
    if (arr[i] <= arr[j])
    {
      res[k++] = arr[i++];
    }
    else
    {
      res[k++] = arr[j++];
      inversionCount += (mid - i);
    }
  }
  while (i <= mid - 1)
  {
    res[k++] = arr[i++];
  }
  while (j <= high)
  {
    res[k++] = arr[j++];
  }
  for (i = 0; i <= high; i++)
  {
    arr[i] = res[i];
  }
  return inversionCount;
}

int mergeSort(int arr[], int res[], int low, int high)
{
  int inversionCount = 0;
  int mid = (high + low) / 2;

  if (high > low)
  {
    inversionCount = mergeSort(arr, res, low, mid);
    inversionCount += mergeSort(arr, res, mid + 1, high);
    inversionCount += merge(arr, res, low, high, mid + 1);
  }
  return inversionCount;
}

int main()
{
  int array1[] = {9, 1, 6, 4, 5};
  int n = 5;
  int res[n];
  cout << "Number of inversions are " << mergeSort(array1, res, 0, n - 1);
}

/* Try more Inputs
case 1:
actual = arrayInversion([3, 2, 1],3)
expected = 3

case2:
 actual = arrayInversion([4, 1, 3, 2],4)
 expected = 4

case3:
actual = arrayInversion([8, 4, 2, 1],4)
expected = 6
*/
