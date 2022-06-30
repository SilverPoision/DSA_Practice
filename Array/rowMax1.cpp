#include <iostream>
using namespace std;

/*
A 2-D array of 1's and 0's is given. Find the row with max 1's
in Time Complexity O(nlogn) and Space Complexity O(1) .
The array is sorted row wise (all 0's in a row are followed by
all 1's.

Solution :
apply binary search and just find the index and sub with M.
*/

#define M 5
#define N 5

int findRowIndex(int mat[M], int low, int high)
{
  if (low > high)
  {
    return -1;
  }
  int mid = low + ((high - low) / 2);

  if (mid == 0 || mat[mid - 1] == 0 && mat[mid] == 1)
  {
    return mid;
  }
  else if (mat[mid] == 0)
  {
    return findRowIndex(mat, mid + 1, high);
  }
  else
  {
    return findRowIndex(mat, low, mid - 1);
  }
  return -1;
}

int findRow(int mat[M][N])
{
  int rowMax = 0, rowMaxIndex = 0;

  for (int i = 0; i < M; i++)
  {
    int index = findRowIndex(mat[i], 0, M - 1);
    if (index != -1 && (M - index) > rowMax)
    {
      rowMax = M - index;
      rowMaxIndex = i;
    }
  }
  return rowMaxIndex;
}

int main()
{
  int mat[M][N] =
      {
          {0, 0, 0, 1, 1},
          {0, 0, 1, 1, 1},
          {0, 0, 0, 0, 0},
          {0, 1, 1, 1, 1},
          {0, 0, 0, 0, 1}};

  int rowIndex = findRow(mat);

  cout << "Maximum 1's are present in the row " << rowIndex;

  return 0;
}
/* Try more Inputs
case1:
 actual = findRow([[0, 1, 1, 1],
       [0, 0, 1, 1],
       [1, 1, 1, 1],
       [0, 0, 0, 0]])
expected = 2

case2:
actual = findRow([[1, 1, 1],
       [0, 0, 0],
       [1, 1, 0],
       [1, 0, 0]])
expected = 0

case3:
actual = findRow([[0, 0, 0, 1, 1],
       [0, 0, 1, 1, 1],
       [0, 0, 0, 0, 0],
       [0, 1, 1, 1, 1],
       [0, 0, 0, 0, 1]])
expected = 4

*/