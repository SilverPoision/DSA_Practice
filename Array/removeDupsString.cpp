#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

/*
String is given as input that contains only lowercase letters,
remove duplicate letters so that every letter appears once
In O(n) Time Complexity and O(1) Space Complexity

Solution:
1. Make a arr of 256 lenth and put -1 in the ascii of string
ele and then verify them.
*/

string removeDuplicates(string str)
{
  int ascii[256] = {0};

  int length = str.length();
  int i;

  for (i = 0; i < length - 1; i++)
  {
    if (ascii[str[i]] == 0)
    {
      ascii[str[i]]++;
    }
    else if (ascii[str[i]] > 0)
    {
      str.erase(i);
    }
  }

  return str;
}

int main()
{
  string str = "abacbc";
  string str1 = removeDuplicates(str);
  cout << str1 << endl;
  return 0;
}

/* Try more Inputs

case1:
actual = removeDuplicates("cbacdcbc")
expected = "acdb"

case2:
actual = removeDuplicates("Java")
expected = "Jav"

case3:
actual = removeDuplicates("abacbc")
expected = "abc"


*/