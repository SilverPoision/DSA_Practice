#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printAnagram(unordered_map<string, vector<string>> &store)
{
  for (auto it : store)
  {
    cout << "[";
    for (auto it1 : it.second)
    {
      cout << "'" << it1 << "'"
           << ",";
    }
    cout << "],";
  }
}

// function for storing
// the vector of strings into HashMap
void storeInMap(vector<string> &vec)
{
  unordered_map<string, vector<string>> store;
  for (auto it : vec)
  {
    string tempString(it);
    sort(tempString.begin(), tempString.end());

    if (store.find(tempString) == store.end())
    {
      vector<string> tempVec;
      tempVec.push_back(it);
      store[tempString] = tempVec;
    }
    else
    {
      store[tempString].push_back(it);
    }
  }

  printAnagram(store);
}

int main()
{
  // initialize vector of strings
  vector<string> arr;
  arr.push_back("eat");
  arr.push_back("tea");
  arr.push_back("tan");
  arr.push_back("ate");
  arr.push_back("nat");
  arr.push_back("bat");

  // utility function for storing
  // strings into hashmap
  storeInMap(arr);
  return 0;
}

/* Try more Inputs
Case 1:
        vector<string> arr;
        arr.push_back("cat");
        arr.push_back("dog");
        arr.push_back("tac");
        arr.push_back("got");
        arr.push_back("act");


        storeInMap(arr);
        expected = [[cat, tac, act],[dog],[got]]


Case2:
        vector<string> arr;
        arr.push_back("no");
        arr.push_back("on");
        arr.push_back("is");

        storeInMap(arr);
        expected = [["no","on"] ["is"]]

*/