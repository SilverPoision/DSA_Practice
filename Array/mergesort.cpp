#include <iostream>
using namespace std;

void merge(int arr[], int result[], int low, int mid, int high)
{
  int k = low, i = low, j = mid + 1;
  while (i <= mid && j <= high)
  {
    if (arr[i] <= arr[j])
    {
      result[k++] = arr[i++];
    }
    else
    {
      result[k++] = arr[j++];
    }
  }
  while (i <= mid)
  {
    result[k++] = arr[i++];
  }
  while (j <= high)
  {
    result[k++] = arr[j++];
  }

  for (i = low; i <= high; i++)
  {
    arr[i] = result[i];
  }
}

void mergesort(int arr[], int result[], int low, int high)
{
  if (high == low)
  {
    return;
  }

  int mid = ((low + high) / 2);

  mergesort(arr, result, low, mid);
  mergesort(arr, result, mid + 1, high);
  merge(arr, result, low, mid, high);
}

int main()
{
  int i;
  int arr[] = {2, 4, 1, 3, 4, 55, 11, 44, 111, 65, 32};
  auto arr_size = sizeof(arr) / sizeof(arr[0]);
  int res[arr_size];
  mergesort(arr, res, 0, arr_size);

  for (i = 0; i < 11; i++)
  {
    cout << res[i] << endl;
  }
  return 0;
}