#include <bits/stdc++.h>
using namespace std;

void swap(int *ind1, int *ind2)
{
  int temp = *ind1;
  *ind1 = *ind2;
  *ind2 = temp;
}

class findRandom
{
private:
  vector<int> arr;
  unordered_map<int, int> map;

public:
  bool insert(int val)
  {
    if (map.find(val) != map.end())
      return false;

    int index = arr.size();
    arr.push_back(val);
    map[val] = index;
    return true;
  }

  bool remove(int val)
  {
    if (map.find(val) != map.end())
      return false;

    int index = map[val];
    swap(&arr[index], &arr[arr.size() - 1]);
    arr.pop_back();
    map.erase(val);
    return true;
  }

  int getRandom()
  {
    srand(time(NULL));
    int random_index = rand() % arr.size();

    return arr[random_index];
  }

  int search(int val)
  {
    if (map.find(val) != map.end())
    {
      return map[val];
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  findRandom random;
  cout << random.insert(1) << endl;
  cout << random.insert(2) << endl;
  cout << random.insert(20) << endl;
  cout << random.insert(21) << endl;
  cout << random.insert(3) << endl;
  cout << random.search(20) << endl;
  cout << random.remove(3) << endl;
  cout << random.remove(3) << endl;
  cout << random.getRandom() << endl;
  return 0;
}

/* Try more Inputs

Case 1:
findRandom random;
random.insert(1)
random.insert(2)
random.insert(3)
result = random.remove(3)
expected = [True]
Case 2:
findRandom random;
random.insert(1)
random.insert(2)
random.remove(1)
result = random.remove(2)
expected = [True]

*/