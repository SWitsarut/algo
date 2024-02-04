#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int m, int r)
{
  int lSize = m - l + 1;
  int rSize = r - m;

  int *larr = new int[lSize];
  int *rarr = new int[rSize];

  memcpy(larr, arr + l, lSize * sizeof(int));
  memcpy(rarr, arr + (m + 1), rSize * sizeof(int));

  int i = 0;
  int j = 0;
  int k = l;
  while (i < lSize && j < rSize)
  {
    if (larr[i] <= rarr[j])
    {
      arr[k++] = larr[i++];
    }
    else
    {
      arr[k++] = rarr[j++];
    }
  }

  while (i < lSize)
  {
    arr[k++] = larr[i++];
  }
  while (j < rSize)
  {
    arr[k++] = rarr[j++];
  }
  delete[] larr;
  delete[] rarr;
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
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = {4, 5, 6};

  v1.swap(v2);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
  }
  cout << endl;
  delete[] arr;
  return 0;
}