#include <bits/stdc++.h>
#include <climits>
using namespace std;

int *counting(int *arr, int Max, int Min, int n)
{
  int range = (Max - Min) + 1;
  unordered_map<int, int> count;
  for (int i = 0; i < n; i++)
  {
    count[arr[i] - Min]++;
  }
  for (int i = 1; i < range; i++)
  {
    count[i] += count[i - 1];
  }
  int *ret = new int[n];
  for (int i = 0; i < n; i++)
  {
    ret[count[arr[i] - Min] - 1] = arr[i];
    count[arr[i] - Min]--;
  }

  return ret;
}

int main()
{
  int n = 3;
  int *arr = new int[n]{3, 1, 2};
  int Max = arr[0], Min = arr[0];
  for (int i = 1; i < n; i++)
  {
    Max = max(arr[i], Max);
    Min = min(arr[i], Min);
  }
  arr = counting(arr, Max, Min, n);
  for (int i = 0; i < 3; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
