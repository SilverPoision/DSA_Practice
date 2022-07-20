#include <bits/stdc++.h>
using namespace std;
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

int signum(int a, int b)
{
  if (a == b)
  {
    return 0;
  }
  if (a < b)
  {
    return 1;
  }
  if (a > b)
  {
    return -1;
  }
}

void getMedian(double e, priority_queue<double> &maxi, priority_queue<double, vector<double>, greater<double>> &mini, double &m)
{
  switch (signum(maxi.size(), mini.size()))
  {
  case 0:
    if (e > m)
    {
      mini.push(e);
      m = (double)mini.top();
    }
    else
    {
      maxi.push(e);
      m = (double)maxi.top();
    }
    cout << m << endl;
    break;
  case 1:
    if (e > m)
    {
      maxi.push(mini.top());
      mini.pop();
      mini.push(e);
    }
    else
    {
      maxi.push(e);
    }
    m = (maxi.top() + mini.top()) / 2.0;
    cout << m << endl;
    break;

  case -1:
    if (e > m)
    {
      mini.push(e);
    }
    else
    {
      mini.push(maxi.top());
      maxi.pop();
      maxi.push(e);
    }
    m = (maxi.top() + mini.top()) / 2.0;
    cout << m << endl;
    break;

  default:
    break;
  }
}

void findMedian(double A[], int size)
{
  priority_queue<double> s;

  priority_queue<double, vector<double>, greater<double>> g;

  double med = 0;

  for (int i = 0; i < size; i++)
  {
    getMedian(A[i], s, g, med);
  }
}

int main()
{
  double A[] = {12, 4, 5, 3, 8, 7};
  int size = ARRAY_SIZE(A);
  cout << "Median:\n";
  findMedian(A, size);
  return 0;
}