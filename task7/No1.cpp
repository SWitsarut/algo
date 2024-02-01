#include <iostream>
using namespace std;

void charArrPrinter(char *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
  }
  cout << endl;
}

int main()
{
  int n = 4;

  char *arr = new char[n]{'E', 'B', 'A', 'X'};
  charArrPrinter(arr, n);
  return 0;
}