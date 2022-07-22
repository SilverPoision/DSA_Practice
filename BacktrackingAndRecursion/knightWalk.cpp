// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

/* A utility function to check if i,j are
valid indexes for N*N chessboard */

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
      cout << " " << setw(2) << sol[x][y] << " ";
    cout << endl;
  }
}

int solveKTUtil(int r, int c, int move, int sol[N][N])
{
  if (r < 0 || c < 0 || r >= N || c >= N || sol[r][c] > 0)
  {
    return 0;
  }
  else if (move + 1 == (N * N))
  {
    printSolution(sol);
    return 1;
  }

  sol[r][c] = move;
  solveKTUtil(r - 2, c + 1, move + 1, sol);
  solveKTUtil(r - 1, c + 2, move + 1, sol);
  solveKTUtil(r + 1, c + 2, move + 1, sol);
  solveKTUtil(r + 2, c + 1, move + 1, sol);
  solveKTUtil(r + 2, c - 1, move + 1, sol);
  solveKTUtil(r + 1, c - 2, move + 1, sol);
  solveKTUtil(r - 1, c - 2, move + 1, sol);
  solveKTUtil(r - 2, c - 1, move + 1, sol);
  sol[r][c] = 0;
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
  int sol[N][N];

  /* Initialization of solution matrix */
  for (int x = 0; x < N; x++)
    for (int y = 0; y < N; y++)
      sol[x][y] = 0;

  /* Start from 0,0 and explore all tours using
  solveKTUtil() */
  if (solveKTUtil(0, 0, 1, sol) == 0)
  {
    cout << "Solution does not exist" << endl;
    printSolution(sol);

    return 0;
  }
  else
    printSolution(sol);

  return 1;
}

// Driver Code
int main()
{
  // Function Call
  solveKT();
  return 0;
}

// This code is contributed by ShubhamCoder
