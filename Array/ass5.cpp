#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
There are N children standing in a line with some rating value.
You want to distribute a minimum number of candies to these
children such that: Each child must have at least one candy.
The children with higher ratings will have more candies than
their neighbors. You need to write a program to calculate the
minimum candies you must give.

Solution:
1. create 2 arr left and right and compare the ratings arr like this
loop through the rating arr from 1 to n and check
if arr[i] > arr[i-1] then left[i] = left[i-1]+1 esle left[i] = 1;
 and
 loop through the rating arr from n-2 to 0 and check
 if arr[i] > arr[i+1] then right[i] = right[i+1]+1 esle right[i] = 1;

then take the max of each arr with same indexes.


*/

// int distCandiesMy(int arr[], int n, int arr2[])
// {
//   sort(arr, arr + n);

//   int candies = 1;
//   int totalCandiesNeedeed = 0;

//   for (int i = 0; i < n; i++)
//   {

//     if (arr[i] < arr[i + 1])
//     {
//       arr2[i] = candies;
//       totalCandiesNeedeed += candies;
//       candies++;
//     }
//     else
//     {
//       arr2[i] = candies;
//       totalCandiesNeedeed += candies;
//     }
//   }
//   return totalCandiesNeedeed;
// }

int distCandies(int arr[], int n)
{
  int left[] = {1, 1, 1, 1};
  int right[] = {1, 1, 1, 1};
  int sum = 0;

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > arr[i - 1])
    {
      left[i] = left[i - 1] + 1;
    }
  }

  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] > arr[i + 1])
    {
      right[i] = right[i + 1] + 1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    sum += max(left[i], right[i]);
  }

  return sum;
}

int main()
{
  int arr[] = {1, 5, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = distCandies(arr, n);
  cout << sum << endl;

  return 0;
}