#include <bits/stdc++.h>
#define N 4
using namespace std;

int maze[N][N] = {{1, 1, 1, 1},
                  {1, 0, 1, 1},
                  {0, 1, 1, 1},
                  {1, 1, 1, 1}};
bool vistited[N][N];

vector<string> ans;
int i = 0, j = 0;

void findSolution()
{
  if (i == N - 1 && j == N - 1)
  {
    return;
  }
  if (i + 1 < N && maze[i + 1][j] == 1 && !vistited[i + 1][j])
  {
    i++;
    ans.push_back("D");
    vistited[i][j] = true;
    findSolution();
    return;
  }
  else if (j + 1 < N && maze[i][j + 1] == 1 && !vistited[i][j + 1])
  {
    j++;
    ans.push_back("R");
    vistited[i][j] = true;
    findSolution();
    return;
  }
  else if (j - 1 < N && j - 1 >= 0 && maze[i][j - 1] == 1 && !vistited[i][j - 1])
  {
    j--;
    ans.push_back("L");
    vistited[i][j] = true;
    findSolution();
    return;
  }
  else if (i - 1 < N && i - 1 >= 0 && maze[i - 1][j] == 1 && !vistited[i - 1][j])
  {
    i--;
    ans.push_back("U");
    vistited[i][j] = true;
    findSolution();
    return;
  }
}

int main()
{
  for (int k = 0; k < N; k++)
  {
    for (int l = 0; l < N; l++)
    {
      vistited[k][l] = false;
    }
  };
  findSolution();
  for (auto it : ans)
  {
    cout << it << " ";
  }
}
