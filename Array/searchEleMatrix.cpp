#include <bits/stdc++.h>
using namespace std;

/*
Matrix n*n is given, where all elements in any individual row or
column are sorted. In such a matrix, we have to find the
position of a value in O(n) Time Complexity and O(1) Space
Complexity

Solution:
1. check if mat[i][j] == key if yes return if not
2. then check if (mat[i][j] > key) then j-- or i++;
*/

#define n 4

bool search(int mat[n][n], int key)
{
  int i = 0, j = n - 1;
  while (i < n && j >= 0)
  {
    if (mat[i][j] == key)
    {
      return true;
    }
    if (mat[i][j] > key)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
}

int main()
{

  int mat[n][n] = {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {27, 29, 37, 48},
                   {32, 33, 39, 50}};
  bool x = search(mat, 36);

  cout << x << endl;

  return 0;
}

/* Try more Inputs

case1:
 actual = searchElement([[10, 20, 30, 40],
    [15, 25, 36, 46],
    [27, 29, 37, 48],
    [32, 33, 39, 50]],4,32)
 expected = True

case2:
actual = searchElement([[10, 20, 30, 40],
    [15, 25, 36, 46],
    [27, 29, 37, 48],
    [32, 33, 39, 50]],4,59)
expected = False

*/