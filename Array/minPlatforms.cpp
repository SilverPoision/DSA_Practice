#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
List of arrival and departure time is given, Find the minimum
number of platforms are required for the railway as no train
waits

Solution:
1. Sort the departure array
2. Check if arrival[i] < departure[j] if yes then inc platformsNeed++
and i and then checkif the maxPlatforms is less than platformsNeed
if yes then maxPlatforms=platfrosmsNeede
3.if not arrival[i] < departure[j] then platformsneeded-- and j++;
*/

int minPlatform(int arrival[], int departure[], int n)
{
  sort(departure, departure + n);
  int i = 0, j = 0, maxPlatforms = 0, platformsNeeded = 0;
  while (i < n && j < n)
  {
    if (arrival[i] < departure[j])
    {
      platformsNeeded++;
      i++;
      if (platformsNeeded > maxPlatforms)
      {
        maxPlatforms = platformsNeeded;
      }
    }
    else
    {
      platformsNeeded--;
      j++;
    }
  }
  return maxPlatforms;
}

int main()
{
  int arrival[] = {900, 940, 950, 1100, 1500, 1800};
  int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
  int n = 6;
  cout << "Minimum Number of Platforms Required: " << minPlatform(arrival, departure, n);
}

/* Try more Inputs
case 1:
actual = minimumNumberOfPlatform([900,940,950,1100,1500,1800],[910, 1200, 1120, 1130, 1900, 2000],6)
expected = 3

case2:
actual = minimumNumberOfPlatform([200, 210, 300, 320, 350, 500],[230, 340, 320, 430, 400, 520],6)
expected = 3

case3:
actual = minimumNumberOfPlatform([900, 1100, 1235],[1000, 1200, 1240],3)
expected = 1
*/