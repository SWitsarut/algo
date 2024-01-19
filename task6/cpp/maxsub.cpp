#include <iostream>
using namespace std;

int max_subarray_sum(int arr[], int n, int **lmax, int **rmax)
{
  if (n == 1)
  {
    return arr[0];
  }
  else
  {
    int m = n / 2;
    int lmss = max_subarray_sum(arr, m, lmax, rmax);
    int rmss = max_subarray_sum(arr + m, n - m, lmax, rmax);

    int lsum = INT32_MIN, rsum = INT32_MIN, sum = 0;
    for (int i = m; i < n; i++)
    {
      sum += arr[i];
      rsum = max(rsum, sum);
    }
    sum = 0;
    for (int i = m - 1; i >= 0; i--)
    {
      sum += arr[i];
      lsum = max(lsum, sum);
    }
    if (lsum + rsum > max(lmss, rmss))
    {
      *lmax = arr;
      *rmax = arr + n - m;
    }
    return max(max(lmss, rmss), lsum + rsum);
  }
}

int main()
{
  int arr[] = {16, -25, 2, -54, 36, 9, -12, 99};
  int *lmax = arr, *rmax = arr;
  cout << max_subarray_sum(arr, 8, &lmax, &rmax);
  // cout<<arr+1;
  cout << "idx" << lmax - arr << " " << rmax - arr;
  return 0;
}
