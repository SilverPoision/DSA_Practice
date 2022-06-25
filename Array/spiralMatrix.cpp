#include <iostream>
using namespace std;

/*
you are given a matrix of m x n elements (m rows, n columns),
Print all elements of the matrix in spiral order in O(m*n)
Time Complexity and O(1) Space Complexity Asked in: Microsoft,
OLA, PayTm, Oracle

Solution:
*/

#define M 5
#define N 5

void printSpiral(int matrix[M][N], int top, int bottom, int left, int right)
{
  int i = 0, j = 0;
  while (top <= right && left <= bottom)
  {
    i = top;
    for (int i = left; i <= right; i++)
      cout << matrix[top][i] << " ";
    top++;
    j = right;
    for (int i = top; i <= bottom; i++)
      cout << matrix[i][right] << " ";
    right--;
    i = bottom;
    for (int i = right; i >= left; i--)
      cout << matrix[bottom][i] << " ";
    bottom--;
    j = left;
    for (int i = bottom; i >= top; i--)
      cout << matrix[i][left] << " ";
    left++;
  }
}

int main()
{
  int matrix[M][N] =
      {
          {1, 2, 3, 4, 5},
          {16, 17, 18, 19, 6},
          {15, 24, 25, 20, 7},
          {14, 23, 22, 21, 8},
          {13, 12, 11, 10, 9}};

  int top = 0, bottom = M - 1;
  int left = 0, right = N - 1;

  printSpiral(matrix, top, bottom, left, right);

  return 0;
}

/* Try more Inputs
case 1:
actual = spiralPrint(3,3,[[1,2,3],[4,5,6],[7,8,9]])
expected = [[1,2,3,6,9,8,7,4,5]]

case2:
 actual = spiralPrint(3,4,[[1,2,3,4],[5,6,7,8],[9,10,11,12]])
 expected = [1,2,3,4,8,12,11,10,9,5,6,7]

*/