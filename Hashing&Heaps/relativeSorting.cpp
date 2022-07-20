#include <bits/stdc++.h>
using namespace std;

vector<int> customSort(vector<int> &arr1, vector<int> &arr2)
{
  map<int, int> M;
  vector<int> ans;

  for (auto i : arr1)
  {
    M[i] += 1;
  }

  for (auto i : arr2)
  {
    if (M.find(i) != M.end())
    {
      for (int j = 1; j <= M[i]; j++)
      {
        ans.push_back(i);
      }
      M.erase(i);
    }
  }

  for (auto it : M)
  {
    for (auto j = it.second; j > 0; j--)
    {
      ans.push_back(it.first);
    }
  }

  return ans;
}

int main()
{
  vector<int> arr1{5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4};
  vector<int> arr2{3, 5, 7, 2};

  cout << "After sorting the array is : ";

  vector<int> vec = customSort(arr1, arr2);
  for (auto i : vec)
    cout << i << " ";
  cout << endl;

  return 0;
}

/* Try more Inputs
Case 1:
int[] arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
int[] arr2 = { 2,1,4,3,9,6 };
int m = sizeof(arr1) / sizeof(arr1[0]);
int n = sizeof(arr2) / sizeof(arr2[0]);
customSort(arr1, arr2);
expected = [2,2,2,1,4,3,3,9,6,7,19]

Case 1:
int[] arr1 = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
int[] arr2 = {2, 1, 8, 3};
int m = sizeof(arr1) / sizeof(arr1[0]);
int n = sizeof(arr2) / sizeof(arr2[0]);
customSort(arr1, arr2);
expected = [2,2,1,1,8,8,3,5,6,7,9]
*/
