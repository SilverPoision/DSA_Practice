#include <bits/stdc++.h>
using namespace std;

void nextEle(vector<int> arr)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(arr.size());

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    int curr = arr[i];

    while (st.top() >= curr)
    {
      st.pop();
    }

    ans[i] = st.top();
    st.push(curr);
  }

  for (auto it : ans)
  {
    cout << it << " ";
  }
}

int main()
{
  vector<int> arr{2, 1, 5, 6, 2, 3};
  nextEle(arr);
  return 0;
}