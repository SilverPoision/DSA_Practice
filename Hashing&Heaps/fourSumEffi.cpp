#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// Function to check if four sum exists in an array with the given sum
bool fourSum(int arr[], int n, int sum)
{
  // create an empty map
  // `key` —> sum of a pair in the array
  // `value` —> vector storing an index of every pair having that sum
  unordered_map<int, vector<Pair>> map;

  // consider each element except the last element
  for (int i = 0; i < n - 1; i++)
  {
    // start from the i'th element until the last element
    for (int j = i + 1; j < n; j++)
    {
      // calculate the remaining sum
      int val = sum - (arr[i] + arr[j]);

      // if the remaining sum is found on the map,
      // we have found a four sum
      if (map.find(val) != map.end())
      {
        // check every pair having a sum equal to the remaining sum
        for (auto pair : map.find(val)->second)
        {
          int x = pair.first;
          int y = pair.second;

          // if fourSum doesn't overlap, print it and return true
          if ((x != i && x != j) && (y != i && y != j))
          {
            cout << "fourSum Found ("
                 << arr[i] << ", " << arr[j] << ", " << arr[x]
                 << ", " << arr[y] << ")";
            return true;
          }
        }
      }

      // insert the current pair into the map
      map[arr[i] + arr[j]].push_back({i, j});
    }
  }

  // return false if four sum doesn't exist
  return false;
}

int main()
{
  int arr[] = {1, 0, -1, 0, -2, 2};
  int sum = 0;

  int n = sizeof(arr) / sizeof(arr[0]);

  if (!fourSum(arr, n, sum))
  {
    cout << "fourSum Doesn't Exist";
  }

  return 0;
}

/* Try more Inputs
Case 1:
        int arr[] = { 10, 2, 3, 4, 5, 9, 7, 8 };
        int n = array.length;
        int sum = 7;
        int mlist[4] = [];
        System.out.println(FourSumProblem(array, n, sum,mlist));
        expected = [3, 5, 7, 8]

Case2:
        int array[] = { 1, 2, 3, 4, 5, 9, 7, 8 };
        int n = array.length;
        int sum = 23;
        int mlist[4] = [];
        System.out.println(FourSumProblem(array, n, sum,mlist));
        expected = [1, 5, 9, 8]
*/
