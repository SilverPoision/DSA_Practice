#include <iostream>
using namespace std;

// void func(int a)
// {
//   if (a == 5)
//   {
//     return;
//   }
//   func(a + 1);
//   cout << "A is " << a << endl;
// }

int main()
{
  // func(1);
  int arr[] = {1, 23, 4};
  int n = 1;
  cout << n << endl;
  cout << arr[n] << endl;
  cout << arr[n++] << endl;
  cout << n << endl;
  cout << arr[n] << endl;

  return 0;
}