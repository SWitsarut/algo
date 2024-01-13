#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int target;
  cin >> target;
  int aIdx = 0, bIdx = 0;
  bool found = false;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
      if (arr[i] + arr[j] == target)
      {
        found = true;
        aIdx = i;
        bIdx = j;
        break;
      }
    if (found)
      break;
  }
  if (found)
  {
    cout << aIdx << " " << bIdx << endl;
  }
  else
  {
    cout << "-1" << endl;
  }
  return 0;
}