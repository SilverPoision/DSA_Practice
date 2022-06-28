#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*
Find next smallest palindrome larger than this given number
Asked in: Flipkart, Oracle

Solution:
1. if n is even then suppose 2436 then check if the mid-1 > mid
if yes then mid = mid-1 and tale half the array and just replicate the
first half to the second half;
if the mid-1 < mid then just add 1 to mid-1 and do the same;
if n is odd then suppose 28749 then tak mid and compare and
check mid-1 > mid+1 if yes then mid+1 = mid-1 and replicate after the mid;
else mid++ and replicate the  first half to second half.

Exceptions:
If all the no are 9 like 999 then just count the no of 9's and
just put noofnine-1 0's between 2 1's like 999 > 1001;
*/

void printArray(int arr[], int n);

void generateNextPalindrome(int num[], int n)
{
  int mid = 0;
  if (n % 2 == 0)
  {
    mid = n / 2;
    if (num[mid - 1] > num[mid])
    {
      num[mid] = num[mid - 1];
      int j = mid;
      for (int i = 0; i < n; i++)
      {
        if (i > mid - 1)
        {
          num[i] = num[j - 1];
          j--;
        }
      }
    }
    else
    {
      num[mid - 1]++;
      int j = mid;
      for (int i = 0; i < n; i++)
      {
        if (i > mid - 1)
        {
          num[i] = num[j - 1];
          j--;
        }
      }
    }
  }
  if (n % 2 != 0)
  {
    mid = n / 2;
    if (num[mid - 1] > num[mid + 1])
    {
      num[mid + 1] = num[mid - 1];
      int j = mid + 1;
      for (int i = 0; i < n; i++)
      {
        if (i > mid - 1)
        {
          num[i] = num[j - 1];
          j--;
        }
      }
    }
    else
    {
      if (num[mid] == 9) // if we inc 9 then it will be 10 so inted we make it 0 and put a carry on previous no
      {
        num[mid] = 0;
        num[mid - 1] = num[mid - 1] + 1;
      }
      else
      {
        num[mid]++;
      }

      int j = mid + 1;
      for (int i = 0; i < n; i++)
      {
        if (i > mid - 1)
        {
          num[i] = num[j - 1];
          j--;
        }
      }
    }
  }

  printArray(num, n);
}

void printArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int num[] = {2, 4, 9, 8, 2};

  int n = sizeof(num) / sizeof(num[0]);

  generateNextPalindrome(num, n);

  return 0;
}

/* Try more Inputs
case 1:
actual = nextPalindromeProblem([9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2],11)
expected = 94188088149

case2:
 actual = nextPalindromeProblem([1,2,1],3)
 expected = 131

case3:
actual = nextPalindromeProblem([2,3,5,4,5],5)
expected = 23632
*/