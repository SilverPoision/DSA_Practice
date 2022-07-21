#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to generate power set of given set S
void findPowerSet(vector<int> S, vector<int> &output, int index, vector<vector<int>> &ans)
{
  if (index >= S.size())
  {
    ans.push_back(output);
    return;
  }

  findPowerSet(S, output, index + 1, ans);

  int ele = S[index];
  output.push_back(ele);
  findPowerSet(S, output, index + 1, ans);
  output.pop_back();
}

int main()
{
  vector<int> S = {1, 2, 3};

  vector<vector<int>> ans;
  vector<int> output;

  int index = 0;

  findPowerSet(S, output, index, ans);
  for (auto it : ans)
  {
    cout << "[";
    for (auto its : it)
    {
      cout << its << ",";
    }
    cout << "]";
    cout << endl;
  }

  return 0;
}