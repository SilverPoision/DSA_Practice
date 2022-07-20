#include <bits/stdc++.h>
using namespace std;

#define n 4

// A min-heap node
struct node
{
  int element;
  int i;
  int j;

  node(int data, int col, int row)
  {
    this->element = data;
    this->j = row;
    this->i = col;
  }
};

class compare
{
public:
  bool operator()(node *a, node *b)
  {
    return a->element >= b->element;
  };
};

void printOutput(int arr[][n], int size)
{
  priority_queue<node *, vector<node *>, compare> minHeap;

  for (int i = 0; i < size; i++)
  {
    node *temp = new node(arr[i][0], i, 0);
    minHeap.push(temp);
  }

  vector<int> ans;

  while (minHeap.size() > 0)
  {
    node *tempo = minHeap.top();
    ans.push_back(tempo->element);
    minHeap.pop();

    int i = tempo->i;
    int j = tempo->j;

    if (j + 1 < n)
    {
      node *next = new node(arr[i][j + 1], i, j + 1);
      minHeap.push(next);
    }
  }
  for (auto it : ans)
  {
    cout << it << " ";
  }
}

int main()
{

  int arr[][n] = {{1, 3, 5, 7},
                  {2, 4, 6, 8},
                  {0, 9, 10, 11}};
  int k = sizeof(arr) / sizeof(arr[0]);

  cout << "Merged resultant array is " << endl;

  printOutput(arr, k);

  return 0;
}

/* Try more Inputs
Case 1:
        int[][] matrix= {{1, 3, 5},
                {2, 4, 6},
                {0, 9, 10}};

        System.out.println("Merged array is :");
        ArrayList<Integer> finalResult = new ArrayList<Integer>();
        for(int val : mergeKSortedArrays(matrix,3))
        {
            finalResult.add(val);
        }
        expected = [0,1,2,3,4,5,6,9,,10]

Case2:
        int[][] matrix= {1};

        System.out.println("Merged array is :");
        ArrayList<Integer> finalResult = new ArrayList<Integer>();
        for(int val : mergeKSortedArrays(matrix,1))
        {
            finalResult.add(val);
        }
        expected = [1]
*/
