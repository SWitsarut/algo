#include <iostream>
#include <climits>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int target;
  cin >> target;
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int minIdx = 0, maxIdx = 0;
  int diff = INT_MAX; // Use INT_MAX for initialization

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        int curDiff = abs(i - j);
        if (curDiff < diff)
        {
          diff = curDiff;
          minIdx = i;
          maxIdx = j;
        }
      }
    }
  }

  cout << arr[minIdx] << " " << arr[maxIdx] << endl;

  delete[] arr;
  return 0;
}
