#include <bits/stdc++.h>
using namespace std;

void charArrPrinter(char *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
  }
  cout << endl;
}

void permLex(char *arr, int k, int n) {}

int main()
{
  int n = 4;

  char *arr = new char[n]{'E', 'B', 'A', 'X'};
  sort(arr, arr + n);
  
  charArrPrinter(arr, n);
  return 0;
}