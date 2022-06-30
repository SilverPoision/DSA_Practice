#include <bits/stdc++.h>
using namespace std;

int storeWater(int arr[], int n)
{
  int left[n], right[n];
  left[0] = arr[0];
  int water = 0;
  for (int i = 1; i < n; i++)
  {
    left[i] = max(left[i - 1], arr[i]);
  }

  right[n - 1] = arr[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = max(right[i + 1], arr[i]);
  }

  for (int i = 1; i < n - 1; i++)
  {
    water += min(left[i], right[i]) - arr[i];
  }
  return water;
}

int main()
{
  int array1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(array1) / sizeof(array1[0]);
  cout << "Maximum water that can be stored is "
       << storeWater(array1, n);
  return 0;
}