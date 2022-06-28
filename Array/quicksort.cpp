#include <iostream>
using namespace std;

void swap(int *ind1, int *ind2)
{
  auto temp = *ind1;
  *ind1 = *ind2;
  *ind2 = temp;
}

int partition(int arr[], int start, int end)
{
  int pivot = arr[end];
  int pIndex = start;

  for (int i = start; i < end; i++)
  {
    if (arr[i] < pivot)
    {
      swap(&arr[i], &arr[pIndex]);
      pIndex++;
    }
  }
  swap(&arr[pIndex], &arr[end]);
  return pIndex;
}

int quickSort(int arr[], int start, int end)
{
  if (start < end)
  {
    int pIndex = partition(arr, start, end);
    quickSort(arr, start, pIndex - 1);
    quickSort(arr, pIndex + 1, end);
  }
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
  return 0;
}