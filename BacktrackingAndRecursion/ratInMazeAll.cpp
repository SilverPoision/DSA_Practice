#include <bits/stdc++.h>
#define N 4
using namespace std;

int maze[N][N] = {{1, 0, 0, 0},
                  {1, 1, 0, 1},
                  {1, 1, 0, 0},
                  {0, 1, 1, 1}};

bool isSafe(int x, int y, bool visited[N][N])
{
  if ((x >= 0 && x < N) && (y >= 0 && y < N) && maze[x][y] == 1 && !visited[x][y])
  {
    return true;
  }
  else
  {
    return false;
  }
}

void solve(vector<string> &ans, int i, int y, bool visited[N][N], string path)
{
  if (i == N - 1 && y == N - 1)
  {
    ans.push_back(path);
    return;
  }

  visited[i][y] = true;

  int newX = i + 1;
  int newY = y;
  if (isSafe(newX, newY, visited))
  {
    path.push_back('D');
    solve(ans, newX, newY, visited, path);
    path.pop_back();
  }
  newX = i;
  newY = y - 1;
  if (isSafe(newX, newY, visited))
  {
    path.push_back('L');
    solve(ans, newX, newY, visited, path);
    path.pop_back();
  }
  newX = i;
  newY = y + 1;
  if (isSafe(newX, newY, visited))
  {
    path.push_back('R');
    solve(ans, newX, newY, visited, path);
    path.pop_back();
  }
  newX = i - 1;
  newY = y;
  if (isSafe(newX, newY, visited))
  {
    path.push_back('U');
    solve(ans, newX, newY, visited, path);
    path.pop_back();
  }

  visited[i][y] = false;
}

vector<string> findSolution()
{
  vector<string> ans;
  int srcx = 0;
  int srcy = 0;
  if (maze[0][0] == 0)
  {
    return ans;
  }

  bool visited[N][N];

  for (int k = 0; k < N; k++)
  {
    for (int l = 0; l < N; l++)
    {
      visited[k][l] = false;
    }
  };

  string path = "";
  solve(ans, srcx, srcy, visited, path);
  sort(ans.begin(), ans.end());
  return ans;
}

int main()
{
  vector<string> ans = findSolution();
  if (ans.size() == 0)
  {
    cout << "No path found!!";
  }
  for (auto it : ans)
  {
    cout << it << " ";
  }
}
