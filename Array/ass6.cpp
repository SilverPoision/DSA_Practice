#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Given a matrix of M x N elements (M rows, N columns),
Print all elements of the matrix in diagonal order in
Time Complexity O(m*n) and Space Complexity O(1)


Solution :
1.Divide the matrix in 2 half and write two for loops.
2. and iterate over it while increasing j and dec i in first with start
and from last -2 in second
*/

void printDiagonal(vector<vector<int>> matrix)
{

  if (matrix.size() == 0)
  {
    return;
  }

  int M = matrix.size();
  int N = matrix[0].size();
  int i = 0, j = 0;

  for (int k = 0; k < M; k++)
  {
    i = k;
    j = 0;
    while (i >= 0)
    {
      cout << " " << matrix[i][j];
      i--;
      j++;
    }
    cout << endl;
  }
  for (int k = 1; k < M; k++)
  {
    i = M - 1;
    j = k;
    while (j <= N - 1)
    {
      cout << " " << matrix[i][j];
      i--;
      j++;
    }
    cout << endl;
  }
}

int main()
{
  vector<vector<int>> matrix = {
      {1, 2, 3, 4, 5},
      {2, 3, 4, 5, 6},
      {3, 4, 5, 6, 7},
      {4, 5, 6, 7, 8},
      {5, 6, 7, 8, 9}};
  printDiagonal(matrix);
  return 0;
}