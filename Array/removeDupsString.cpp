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
  int *ascii = new int[256];

  int length = sizeof(str) / sizeof(str[0]);

  for (int i = 0; i < length; i++)
  {
    if (ascii[int(str[i])] != -1)
    {
      ascii[int(str[i])] = -1;
    }
    else if (ascii[int(str[i])] == -1)
    {
      cout << "dd" << endl;
      str.erase(i, 1);
    }
  }
  return str;
}

int main()
{
  string str("abacbc");
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