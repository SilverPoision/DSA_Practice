#include <iostream>
using namespace std;

/*
Find kth smallest element in that in an unsorted integer array
in Time Complexity O(n) and Space Complexity O(1) Asked in :
Vmware, SapLabs, WalmartLabs

Solution:
In QuickSort, we pick a pivot element, then move the pivot
element to its correct position and partition the surrounding
array. The idea is, not to do complete quicksort, but stop at
the point where pivot itself is k’th smallest element. Also,
not to recur for both left and right sides of pivot, but recur f
or one of them according to the position of pivot. The worst
case time complexity of this method is O(n2), but it works in O(n) on average.
*/

void swap(int *ind1, int *ind2)
{
  auto temp = *ind1;
  *ind1 = *ind2;
  *ind2 = temp;
}

int randomPartition(int array1[], int l, int r)
{
  int pIndex = l;
  int pivot = r;

  for (int i = l; i < r; i++)
  {
    if (array1[i] <= array1[pivot])
    {
      swap(&array1[i], &array1[pIndex]);
      pIndex++;
    }
  }
  swap(&array1[pIndex], &array1[pivot]);
  return pIndex;
}

int findKthSmallest(int array1[], int l, int r, int k)
{

  if (k > 0 && k <= r - l + 1)
  {
    int pivot = randomPartition(array1, l, r);
    if (pivot - l == k - 1)
    {
      return array1[pivot];
    }
    if (pivot - l > k - 1)
    {
      return findKthSmallest(array1, l, pivot - 1, k);
    }

    return findKthSmallest(array1, pivot + 1, r, k - pivot + l - 1);
  }
  return INT_MAX;
}

int main()
{
  int array1[] = {7, 10, 4, 3, 20, 15};
  int n = sizeof(array1) / sizeof(array1[0]), k = 3;
  cout << "K'th smallest element is " << findKthSmallest(array1, 0, n - 1, k);
  return 0;
}

/* Try more Inputs
case 1:
actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,3)
expected = 7

case2:
 actual = findKthElement([7, 10, 4, 3, 20, 15],0,5,4)
 expected = 10

case3:
actual = findKthElement([12, 3, 5, 7, 19],0,4,2)
expected = 5
*/