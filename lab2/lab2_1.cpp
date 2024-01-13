#include <iostream>
using namespace std;

void interSearch(int *arr, int l, int target, int r)
{
  int m = l + (((target - arr[l]) * (r - l)) / (arr[r] - arr[l]));
  cout << m << " ";

  if (arr[m] == target)
    return;

  if (target < arr[m])
    interSearch(arr, l, target, m - 1);
  else
    interSearch(arr, m + 1, target, r);
}

int main()
{
  int n = 6;
  cin >> n;
  int target = 5;
  cin >> target;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  interSearch(arr, 0, target, n - 1);
  cout << endl;
  return 0;
}
