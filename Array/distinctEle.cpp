#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a number K. Find the count of
distinct elements in every window of size K in the array in
Time Complexity : O(n) and Space Complexity: O(n)


Solution:
Create an empty hash map. Let the hash map be hM.
Initialize the count of distinct elements as dist_count to 0.
Traverse through the first window and insert elements of the first window to hM. The elements are used as key and their counts as the value in hM. Also, keep updating dist_count
Print distinct count for the first window.
Traverse through the remaining array (or other windows).
Remove the first element of the previous window.
If the removed element appeared only once, remove it from hM and decrease the distinct count, i.e. do “dist_count–“
else (appeared multiple times in hM), then decrement its count in hM
Add the current element (last element of the new window)
If the added element is not present in hM, add it to hM and increase the distinct count, i.e. do “dist_count++”
Else (the added element appeared multiple times), increment its count in hM
*/

void findDistinctCount(int arr[], int n, int k)
{
  unordered_map<int, int> hm;

  int dist_count = 0;

  for (int i = 0; i < k; i++)
  {
    if (hm[arr[i]] == 0)
    {
      dist_count++;
    }
    hm[arr[i]] += 1;
  }

  cout << dist_count << endl;

  for (int i = k; i < n; i++)
  {
    if (hm[arr[i - k]] == 1)
    {
      dist_count--;
    }
    hm[arr[i - k]] -= 1;

    if (hm[arr[i]] == 0)
    {
      dist_count++;
    }
    hm[arr[i]] += 1;

    cout << dist_count << endl;
  }
}

int main()
{
  int arr[] = {1, 2, 1, 3, 4, 2, 3};
  int k = 4;

  int n = sizeof(arr) / sizeof(arr[0]);
  findDistinctCount(arr, n, k);

  return 0;
}

// for (int l = 0; l < 5; l++)
// {
//   cout << l << " " << seen[l] << endl;
// }
// cout << "i: " << i << " "
//      << "j: " << j << " "
//      << "start: " << start << endl;

// if (j <= 1)
//     {
//       start++;
//       j = k;
//       i = start;
//       cout << seen[20] << endl;
//       for (int l = 0; l < 21; l++)
//       {
//         seen[l] = 0;
//       }
//       if (i + j > n)
//       {
//         break;
//       }
//       continue;
//     }
//     if (seen[arr[i]] == 1)
//     {
//       i++;
//       j--;
//       continue;
//     }
//     else
//     {
//       i++;
//       j--;
//       seen[arr[i]] = 1;
//       seen[20]++;
//     }
//   }