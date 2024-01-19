#include <iostream>
using namespace std;
// int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int arr[] = {6, 3, 1, 2, 4, 5, 8, 7, 9};
int k = 4;
int n = sizeof(arr) / sizeof(arr[0]);
int count = 0;

void printArray()
{
  cout << ": \t";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int partition(int l, int r)
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
  cout << "pivot idx :" << mot << " pivot val" << pivotVal << endl;
  cout << count << "ori";
  printArray();
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
  swap(arr[i], arr[j]);
  cout << count;
  printArray();
  return i;
}

int quickSelect(int low, int high, int k)
{
  if (low == high)
    return arr[low];
  int p = partition(low, high);
  if (p == k - 1) // case k = Pivot position
    return arr[p];
  else if (k < p) // case k  L
    return quickSelect(low, p - 1, k);
  else
  {
    k = k - p + low;
    return quickSelect(p + 1, high, k);
  }
}
int main()
{
  printf("ans %d\n", quickSelect(0, n - 1, k));
  printArray();
  return 0;
}

// T(1) = 1;
// T(n) = T(n/2) + n
//
// T(n/2) = T(n/4) + n/2 +n
// T(n/4) = T(n/8) + n/4 + n/2 +n
// T(n) = T(n/2k) + n* r^n -1 / r - 1
//
