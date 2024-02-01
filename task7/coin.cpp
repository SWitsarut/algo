#include <bits/stdc++.h>
#include <climits>
using namespace std;

template <typename T>
void arrayPrinter(T *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}
bool checkValid(bool *arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    if (arr[i] && arr[i - 1])
    {
      return false;
    }
  }
  arrayPrinter(arr, n);
  return true;
}
int subset(int *val, bool *arr, int k, int n)
{
  if (k == n)
  {
    if (!checkValid(arr, n))
    {
      return INT_MIN;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i])
      {
        sum += val[i];
      }
    }
    cout << "sum " << sum << endl;
    return sum;
  }
  else
  {
    arr[k] = 1;
    int maxUp = subset(val, arr, k + 1, n);
    arr[k] = 0;
    int maxDown = subset(val, arr, k + 1, n);
    return max(maxUp, maxDown);
  }
}

int main()
{
  int *val = new int[10]{30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
  bool *arr = new bool[10];
  memset(arr, false, 10);
  cout << "max = " << subset(val, arr, 0, 10);
  return 0;
}