#include <iostream>
#include <cstring>
using namespace std;

/*
find an arrangement of N queens on a chess board, such that no
queen can attack any other queens on the board. The chess queens
can attack in any direction as horizontal, vertical, horizontal
and diagonal way [Asked in : VISA, Intuit]
*/

// N x N chessboard
#define N 5

void printSolution(int board[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << " " << board[i][j] << " ";
    printf("\n");
  }
}

bool isSafe(int board[N][N], int col, int row)
{
  int i, j;

  for (i = col, j = row; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j] == 1)
      return false;
  }

  for (i = col, j = row; i < N && j >= 0; i++, j--)
  {
    if (board[i][j] == 1)
      return false;
  }

  for (i = col; i >= 0; i--)
  {
    if (board[i][row])
      return false;
  }
  return true;
}

bool nQueen(int board[N][N], int col)
{
  if (col >= N)
  {
    return true;
  }
  for (int i = 0; i < N; i++)
  {
    if (isSafe(board, col, i))
    {
      board[col][i] = 1;

      if (nQueen(board, col + 1))
        return true;

      board[col][i] = 0;
    }
  }

  return false;
}

int main()
{
  // mat[][] keeps track of position of Queens in current configuration
  int board[N][N] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};

  if (nQueen(board, 0) == false)
  {
    cout << "Solution does not exist";
    return 0;
  }

  printSolution(board);
  return 0;
}