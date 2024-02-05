#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int lexicography(int *arr, int *nums, int n, int k, int c, bool used[])
{
  if (c == k)
  {
    for (int i = 0; i < k; i++)
    {
      cout << nums[arr[i]] << " ";
    }
    cout << "\n";
    return 1;
  }
  else
  {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (!used[i])
      {
        arr[c] = i;
        used[i] = true;
        sum += lexicography(arr, nums, n, k, c + 1, used);
        used[i] = false;
      }
    }
    return sum;
  }
} 

int main()
{
  int n, k;
  cin >> n >> k;
  int nums[n];
  for (int i = 1; i <= n; i++)
  {
    nums[i - 1] = i;
  }

  bool used[n] = {false};
  cout << lexicography(new int[n], nums, n, k, 0, used);

  return 0; 
}