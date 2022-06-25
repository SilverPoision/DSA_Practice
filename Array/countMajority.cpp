#include <iostream>
using namespace std;

/*
 Given an array of integer, write an efficient algorithm to
 find majority number in that array in Time Complexity O(n) and
 Space Complexity O(1)

 Solution:
 1. set ele = arr[0] and run a loop from i =1 amd check if the
 ele == arr[i] if yes then count++ else count--
 2. Check if the count == 0 if yes then update the majority ele
 and count=1;

 O(N),O(1);
*/

// Function to return majority element present in given array
int majorityElement(int arr[], int n)
{
  int count = 1, ele = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (ele == arr[i])
    {
      count++;
    }
    else
    {
      count--;
    }
    if (count == 0)
    {
      ele = arr[i];
      count = 1;
    }
  }
  return ele;
}

int main(void)
{
  int arr[] = {3, 2, 2, 2, 2, 2, 2, 8, 3, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Majority element is %d \n", majorityElement(arr, n));

  return 0;
}