#include <iostream>
using namespace std;

int max_subarray_sum(int *arr, int n)
{
  if (n == 1)
  {
    return arr[0];
  }
  else
  {
    int m = n / 2;
    int lmss = max_subarray_sum(arr, m);
    int rmss = max_subarray_sum(arr + m, n - m);

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
    return max(max(lmss, rmss), lsum + rsum);
  }
}

int main()
{
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // int arr[] = {16, -25, 2, -54, 36, 9, -12, 66};
  cout << max_subarray_sum(arr, n)<<endl;
  // cout<<arr+1;
  return 0;
}
