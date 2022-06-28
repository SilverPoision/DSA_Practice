#include <bits/stdc++.h>
using namespace std;

#define n 4
/*
You are in a party of N people, where only one person is known
to everyone. Such a person may be present at the party, if yes,
(s)he doesn’t know anyone at the party. Your task is to find the
celebrity at the party in Time Complexity O(n) Asked in: Google,
Flipkart, Amazon, Microsoft

Solution:
1. Just check in which row all the elements are zero and there cab be
only one 1 and that also when i == j and zero = 0;
*/

// Person with 2 is celebrity
bool MATRIX[n][n] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
  return MATRIX[a][b];
}

int findCelebrityMy()
{
  int ele = -1;
  bool isAllZero = false;
  int i = 0, j = 0;
  while (i < n && j < n)
  {
    if (knows(i, j) == 0)
    {
      if (j == n - 1)
      {
        if (isAllZero == true)
        {
          ele = i;
          break;
        }
        i++;
        j = 0;
        isAllZero = true;
        continue;
      }
      j++;
      isAllZero = true;
      continue;
    }
    else if (i == j && isAllZero == true && knows(i, j) == 1)
    {
      ele = i;
      break;
    }
    else
    {
      ele = -1;
      i++;
      j = 0;
      isAllZero = false;
    }
  }
  return ele;
}

// int findCelebrity(int n)
// {
//     // Initialize two pointers as two corners
//     int X = 0;
//     int Y = n - 1;

//     // Keep moving while the two pointers don't become same.
//     while (X < Y)
//     {
//         if (knows(X, Y))
//             X++;
//         else
//             Y--;
//     }

//     // Check if X is actually a celebrity or not
//     for (int i = 0; i < n; i++)
//     {
//         // If any person doesn't  know 'X' or 'X' doesn't know any person, return -1
//         if ( (i != X) &&
//                 (knows(X, i) ||
//                 !knows(i, X)) )
//             return -1;
//     }

//     return X;
// }

int main()
{
  int id = findCelebrityMy();
  id == -1 ? cout << "No celebrity Found" : cout << "Celebrity ID is " << id;
  return 0;
}

/* Try more Inputs
case 1:
static int matrix[][] = {{0 1 0},
                         {0 0 0},
                         {0 1 0}};
expected = 1

case2:
static int matrix[][] = {{0 1},
                        {1 0}};
 expected = -1

Note: The two people at the party both
know each other. None of them is a celebrity

case 3:
static int matrix[][] = { {0, 0, 1, 0},
                            {0, 0, 1, 0},
                         {0, 1, 0, 0},
                         {0, 0, 1, 0} };
expected = -1
*/
