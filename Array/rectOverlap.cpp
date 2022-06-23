#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Rectangle that is represented as a list [x1, y1, x2, y2],
where (x1, y1) is the coordinates of its top-left corner,
and (x2, y2) is the coordinates of its bottam-right corner.
Now two rectangles overlap if the area of their intersection
is positive.Two rectangles that only touch at the corner or
edges do not overlap.Check in O(1) Time complexity and O(1)
Space complexity that both rectangle overlap or not Asked in:
GoldmanSachs, Expedia, OLA

Example:

Input: rec1 = [0,8,8,0], rec2 = [5,5,15,0]

Solution:

x co-ordinate(top left point of one react) > x co-ordinate
(bottom roght poimt of other rect)
y co-ordinate(top left point of one react) < y co-ordinate
(bottom rigth poimt of other rect)
*/

struct Point
{
  int x, y;
};

// Returns true if two rectangles (l1, r1) and (l2, r2) overlap
bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
  if (l1.x > r2.x || l2.x > r1.x)
  {
    return false;
  }
  if (l1.y < r2.y || l2.y < r1.y)
  {
    return true;
  }
  return true;
}

int main()
{
  Point l1 = {0, 10}, r1 = {10, 0};
  Point l2 = {5, 5}, r2 = {15, 0};
  if (doOverlap(l1, r1, l2, r2))
    printf("Rectangles Overlap");
  else
    printf("Rectangles Don't Overlap");
  return 0;
}