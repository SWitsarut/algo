#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid,
           int right)
{
  int LSize = mid - left + 1;
  int RSize = right - mid;

  int *lArr = new int[LSize], *rArr = new int[RSize];

  for (int i = 0; i < LSize; i++)
    lArr[i] = arr[left + i];
  for (int j = 0; j < RSize; j++)
    rArr[j] = arr[mid + 1 + j];

  int idxLarr = 0, idxRarr = 0;
  int k = left;

  while (idxLarr < LSize && idxRarr < RSize)
  {
    if (lArr[idxLarr] <= rArr[idxRarr])
    {
      arr[k] = lArr[idxLarr];
      idxLarr++;
    }
    else
    {
      arr[k] = rArr[idxRarr];
      idxRarr++;
    }
    k++;
  }

  while (idxLarr < LSize)
  {
    arr[k] = lArr[idxLarr];
    idxLarr++;
    k++;
  }

  while (idxRarr < RSize)
  {
    arr[k] = rArr[idxRarr];
    idxRarr++;
    k++;
  }
  delete[] lArr;
  delete[] rArr;
}

void mergeSort(int *arr, int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()
{
  int n = 4;
  int *arr = new int[n]{5, 3, 1, 2};
  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
  }
  cout << endl;
  return 0;
}