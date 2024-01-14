#include <iostream>
using namespace std;

void merge(int arr[], int const left, int const mid,
           int const right)
{
  int const Lstart = mid - left + 1;
  int const Rstart = right - mid;

  int *lArr = new int[Lstart], *rArr = new int[Rstart];

  for (int i = 0; i < Lstart; i++)
    lArr[i] = arr[left + i];
  for (int j = 0; j < Rstart; j++)
    rArr[j] = arr[mid + 1 + j];

  int idxLarr = 0, idxRarr = 0;
  int k = left;

  while (idxLarr < Lstart && idxRarr < Rstart)
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

  while (idxLarr < Lstart)
  {
    arr[k] = lArr[idxLarr];
    idxLarr++;
    k++;
  }

  while (idxRarr < Rstart)
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
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}

// int main()
// {
//   int arr[5] = {4, 2, 1, 3, 7};
//   int size = sizeof(arr) / sizeof(int);
//   mergeSort(arr, 0, size - 1);
//   for (int i = 0; i < size; i++)
//   {
//     cout << arr[i] << " ";
//   }
//   cout << endl;
//   return 0;
// }