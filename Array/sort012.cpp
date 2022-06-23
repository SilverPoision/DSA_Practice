#include <iostream>
using namespace std;

int *sortOne(int arr[], int size)
{
  int i;
  int a = 0;
  int b = 0;
  int c = 0;
  for (i = 0; i < size; i++)
  {
    if (arr[i] == 0)
    {
      a++;
    }
    else if (arr[i] == 1)
    {
      b++;
    }
    else if (arr[i] == 2)
    {
      c++;
    }
  }

  i = 0;
  cout << a << b << c << endl;

  while (a != 0 || b != 0 || c != 0)
  {
    if (a > 0)
    {

      arr[i] = 0;
      a--;
      i++;
    }
    else if (b > 0)
    {

      arr[i] = 1;
      b--;
      i++;
    }
    else if (c > 0)
    {

      arr[i] = 2;
      c--;
      i++;
    }
  }
  cout << a << b << c << endl;
  return arr;
}

int main()
{
  int arr[] = {1, 2, 0, 2, 2, 1, 1, 0, 0, 1, 1, 2, 2, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *resArr = sortOne(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout << resArr[i] << endl;
  }
  return 0;
}