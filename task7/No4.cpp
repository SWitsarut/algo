#include <iostream>
using namespace std;

void subset(bool *bin, int *arr, int n, int k, int *count)
{
  if (k < 0)
  {
    for (int i = 0; i < n; i++)
    {
      if (bin[i])
      {
        cout << "1";
      }
      else
      {
        cout << "0";
      }
    }
    cout << "\t";
    bool isZero = true;
    for (int i = 0; i < n; i++)
    {
      if (bin[i])
      {
        cout << arr[i];
        isZero = false;
      }
    }
    if (isZero)
      cout << "0";
    cout << endl;
    *count = *count + 1;
  }
  else
  {
    bin[k] = false;
    subset(bin, arr, n, k - 1, count);
    bin[k] = true;
    subset(bin, arr, n, k - 1, count);
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
  int count = 0;
  subset(new bool[n]{false}, arr, n, n, &count);
  cout << "does :" << count;
  return 0;
}