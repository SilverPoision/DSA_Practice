#include <bits/stdc++.h>
using namespace std;

/*
An array is given as Input where ith element is the price of a
given stock on day You were permitted to complete unlimited
transaction. Derive an algorithm to find the maximum profit in
O(n) Time complexity and O(n) Space Complexity Asked in: Amazon,
Microsoft, Flipkart, DE-Shaw

Solution:
1. Make 3 var buy sell and profit and find the local minima and
local maxima by the below 2 while loops.
2. Then subt sell from buy and add to profit.
*/

// function finds the buy sell
//  schedule for maximum profit
int findProfit(int arr[], int n)
{
  int i = 0;
  int buy = 0, sell = 0, profit = 0;
  while (i < n)
  {
    while (i < n)
    {
      if (arr[i] < arr[i + 1])
      {
        buy = arr[i];
        break;
      }
      i++;
    }
    while (i < n)
    {
      if (buy < arr[i] && arr[i] > arr[i + 1])
      {
        sell = arr[i];
        profit += sell - buy;
        break;
      }
      i++;
    }
  }
  return profit;
}

int main()
{
  int array1[] = {1, 2, 3, 4, 5};
  int n = sizeof(array1) / sizeof(array1[0]);

  int profit = findProfit(array1, n);
  cout << profit << endl;
  return 0;
}

/* Try more Inputs
case 1:
actual = findProfit([7,1,5,3,6,4],6)
expected = 2

Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3

case2:
 actual = findProfit([1,2,3,4,5],5)
 expected = 4
 Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4

case3:
actual = findProfit([7,6,4,3,1],5)
expected = 0
In this case, no transaction is done, i.e., max profit = 0
*/