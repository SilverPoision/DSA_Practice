#include <bits/stdc++.h>
using namespace std;

/*
Two n-ary trees given , Check if they are mirror of each other
or not In Time and Space Complexity O(n) Asked in :
Google, Uber
*/

// First vector stores all nodes and adjacent of every
// node in a stack.
// Second vector stores all nodes and adjacent of every
// node in a queue.
bool findMirror(vector<stack<int>> &tree1,
                vector<queue<int>> &tree2)
{
  for (int i = 1; i < tree1.size(); ++i)
  {
    stack<int> &s = tree1[i];
    queue<int> &q = tree2[i];

    while (!s.empty() && !q.empty())
    {
      if (s.top() != q.front())
      {
        return false;
      }

      s.pop();
      q.pop();
    }

    if (!s.empty() || !q.empty())
    {
      return false;
    }
  }
  return true;
}

// Returns true if given two trees are mirrors.
// A tree is represented as two arrays to store
// all tree edges.
void checkMirrorTree(int m, int n, int arr1[], int arr2[], int u2[], int v2[])
{
  vector<stack<int>> tree1(m + 1);
  vector<queue<int>> tree2(m + 1);

  for (int i = 0; i < n; i++)
  {
    tree1[arr1[i]].push(arr2[i]);
  }

  for (int i = 0; i < n; i++)
  {
    tree2[u2[i]].push(v2[i]);
  }

  findMirror(tree1, tree2) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

int main()
{
  int M = 3, N = 2;

  int arr1[] = {2, 2};
  int arr2[] = {3, 4};

  int u2[] = {2, 2};
  int v2[] = {4, 3};

  checkMirrorTree(M, N, arr1, arr2, u2, v2);

  return 0;
}