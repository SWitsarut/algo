#include <iostream>
using namespace std;

int count = 0;

int partition(int *arr, int l, int r)
{
  count++;

  int mot = (l + r) / 2;
  if (arr[l] > arr[r])
  {
    swap(arr[l], arr[r]);
  }
  if (arr[l] > arr[mot])
  {
    swap(arr[l], arr[mot]);
  }
  if (arr[mot] > arr[r])
  {
    swap(arr[mot], arr[r]);
  }
  int pivotVal = arr[mot];
  swap(arr[l], arr[mot]);
  int i = l;
  int j = r;
  do
  {
    while (arr[i] < pivotVal)
    {
      i++;
    }
    while (arr[j] > pivotVal)
    {
      j--;
    }
    swap(arr[i], arr[j]);
  } while (i < j);
  return i;
}

int quickSelect(int *arr, int low, int high, int k)
{
  if (low == high)
    return arr[low];
  int p = partition(arr, low, high);
  if (p == k - 1)
    return arr[p];
  else if (k < p)
    return quickSelect(arr, low, p - 1, k);
  else
  {
    k = k - p + low;
    return quickSelect(arr, p + 1, high, k);
  } 
}

int main()
{
  int n = 7;
  cin >> n;
  int target = 3;
  cin >> target;
  int *arr = new int[n]{1, 5, 10, 4, 8, 2, 6};
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // cout << arr[target - 1] << endl;

  cout << quickSelect(arr, 0, n - 1, target) << " " << count << endl;
  return 0;
}