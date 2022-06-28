#include <bits/stdc++.h>
using namespace std;

/*
Find square root of Guven Num without sqrt() function in Time
Complexity O(Logn) and No Space Complexity Asked in : Accolite,
Qualcomm
*/

int findSqrt(int x)
{
  int start = 1, end = x, ans = 0;
  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (mid * mid == x)
    {
      return mid;
    }
    if (mid * mid < x)
    {
      start = mid + 1;
      ans = mid;
    }
    else
    {
      end = mid - 1;
    }
  }
  return ans;
}

int main()
{
  int x = 8;
  cout << findSqrt(x) << endl;
  return 0;
}

/* Try more Inputs
case 1:
actual = findSqrt(4)
expected = 2

case2:
 actual = findSqrt(11)
 expected = 3
*/