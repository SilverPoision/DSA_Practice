#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallEle(int arr[], int n)
{
  vector<int> ans(n);
  stack<int> s;
  s.push(-1);

  for (int i = n - 1; i >= 0; i--)
  {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr)
    {
      s.pop();
    }
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

vector<int> prevSmallEle(int arr[], int n)
{
  vector<int> ans(n);
  stack<int> s;
  s.push(-1);

  for (int i = 0; i < n; i++)
  {
    int curr = arr[i];
    while (s.top() != -1 && arr[s.top()] >= curr)
    {
      s.pop();
    }
    ans[i] = s.top();
    s.push(i);
  }
  return ans;
}

// function to find the maximum rectangular
// area under given histogram with n bars
int getMaxArea(int hist[], int n)
{
  vector<int> next = nextSmallEle(hist, n);
  vector<int> prev = prevSmallEle(hist, n);
  int area = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    int l = hist[i];

    if (next[i] == -1)
    {
      next[i] = n;
    }

    int b = next[i] - prev[i] - 1;

    area = max(l * b, area);
  }
  return area;
}

int main()
{
  int hist[] = {2, 1, 5, 6, 2, 3};
  int n = sizeof(hist) / sizeof(hist[0]);
  cout << "Maximum area is " << getMaxArea(hist, n);
  return 0;
}

/* Try more Inputs
Case 1:
int hist[] = {2,1,5,6,2,3};
int n = sizeof(hist)/sizeof(hist[0]);
int expected = getMaxArea(hist, n);
expected = 10

Case2:
int hist[] = {6, 2, 5, 4, 5, 1, 6};
int n = sizeof(hist)/sizeof(hist[0]);
int expected = getMaxArea(hist, n);
expected = 12
*/