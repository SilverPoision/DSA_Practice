#include <iostream>
using namespace std;

/*
Given an array where every element occurs two times, except one
element which occurs only once. Find the element that occurs
once. Expected time complexity is O(n) and O(1) extra space
Asked in : Flipkart, Amazon, PayTm

Solution :
Take xor of arr[i] and arr[i+1]  and store the result and do this for all

*/

int main()
{
  int nums[] = {1, 2, 1, 3, 4, 3, 2};
  int result = nums[0]; // Start with the first element
  for (int i = 1; i < 7; i++)
  {
    result ^= nums[i];
  }
  cout << result << endl;
}

/* Try more Inputs
case 1:
actual = main([-1,2,-1,3,2])
expected = 3

case2:
 actual = main([9,4,9,6,4])
 expected = 6

case3:
actual = main([1,1,2,2,3,3,4])
expected = 4
*/