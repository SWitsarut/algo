#include <iostream>
using namespace std;

int count = 0;
int partition(int a[], int l, int r)
{
  int pivot, i, j, t;
  pivot = a[l]; // first item always as the pivot
  i = l;
  j = r + 1;
  while (1)
  {
    do
    {
      ++i;

    } while (a[i] <= pivot);
    do
    {
      --j;
    } while (a[j] > pivot);

    if (i >= j)
      break;
    swap(a[i], a[j]);
  }
  swap(a[l], a[j]);
  return j;
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
  int *arr = new int[10]{2, 32, 1, 3, 0, 4, 5, 9, 23, 19};
  int smallestNth = quickSelect(arr, 0, 9, -1);
  cout << smallestNth;
  return 0;
}