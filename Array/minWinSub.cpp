#include <bits/stdc++.h>
using namespace std;

/*
Given two strings string1 and string2 , return the minimum
window in string1 which will contain all the characters in
string2 in Time Complexity O(n) and Space Complexity O(1)

Solution:
First check if the length of the string is less than the length
of the given pattern, if yes then “no such window can exist “.
Store the occurrence of characters of the given pattern in a
hash_pat[].
we will be using two pointer technique basically
Start matching the characters of pattern with the characters of
string i.e. increment count if a character matches.
Check if (count == length of pattern ) this means a window is
found.
If such a window found, try to minimize it by removing extra
characters from the beginning of the current window.
delete one character from first and again find this deleted key
at right, once found apply step 5 .
Update min_length.
Print the minimum length window.
*/

const int no_of_chars = 256;

string findMinWindow(string str, string ptr)
{
  int len1 = str.length();
  int len2 = ptr.length();

  if (len1 < len2)
  {
    cout << "No such window exists" << endl;
  }

  int hashPtr[no_of_chars] = {0};
  int hashStr[no_of_chars] = {0};

  for (int i = 0; i < len2; i++)
    hashPtr[ptr[i]]++;

  int start = 0, start_index = -1, min_len = INT_MAX;

  int count = 0;

  for (int i = 0; i < len1; i++)
  {
    hashStr[str[i]]++;

    // If string's char matches with ptrtern's char
    // then increment count
    if (hashPtr[str[i]] != 0 && hashStr[str[i]] <= hashPtr[str[i]])
    {
      count++;
    }

    if (count == len2)
    {
      // Try to minimize the window i.e., check if
      // any character is occurring more no. of times
      // than its occurrence in ptrtern, if yes
      // then remove it from starting and also remove
      // the useless characters.
      while (hashStr[str[start]] > hashPtr[str[start]] || hashPtr[str[start]] == 0)
      {
        if (hashStr[str[start]] > hashPtr[str[start]])
          hashStr[str[start]]--;
        start++;
      }

      int len_window = i - start + 1;

      if (min_len > len_window)
      {
        min_len = len_window;
        start_index = start;
      }
    }
  }

  if (start_index == -1)
  {
    cout << "No such window Exists";
    return "";
  }

  return str.substr(start_index, min_len);
}

int main()
{
  string str = "aabcbcdbca";
  string ptr = "abcd";

  cout << "Smallest window is : \n"
       << findMinWindow(str, ptr);
  return 0;
}

/* Try more Inputs
case 1:
actual = findMinWindow("a","a")
expected = Smallest window is : a

case2:
 actual = findMinWindow("zaaskzaa", "zsk")
 expected = Smallest window is : skz

case3:
actual = findMinWindow("tutorial","oti")
expected = Smallest window is : tori


*/