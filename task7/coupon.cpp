#include <bits/stdc++.h>
using namespace std;

bool atLeast3books(bool *bin, int n)
{
  int sum = 0;
  for (size_t i = 0; i < n; i++)
    sum += bin[i];
  return sum >= 3;
}

int getSum(bool *bin, int *val, int n)
{
  int sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (bin[i])
      sum += val[i];
  }
  return sum;
}

bool *subset(bool *bin, int *val, int target, int k, int n, bool *binClose)
{
  if (k == n)
  {
    bool valid = false;
    if (atLeast3books(bin, n))
    {
      int sum = getSum(bin, val, n);
      valid = sum <= target;
    }
    if (valid)
    {
      bool *ret = new bool[n];
      memcpy(ret, bin, n);
      return ret;
    }
    else
    {
      bool *empty = new bool[n]{false};
      return empty;
    }
  }
  else
  {
    bin[k] = true;
    bool *left = subset(bin, val, k + 1, target, n, binClose);
    bin[k] = false;
    bool *right = subset(bin, val, k + 1, target, n, binClose);
    int leftSum = target - getSum(left, val, n);
    int rightDiff = target - getSum(right, val, n);
    if (leftSum > rightDiff)
    {
      delete[] left;
      return right;
    }
    else
    {
      delete[] right;
      return left;
    }
  }
}

int main()
{
  int n = 8;
  int target = 600;
  int *val = new int[n]{136, 411, 211, 200, 275, 189, 232, 375};
  bool *bin = new bool[n];
  memset(bin, true, n);
  bool *closest = new bool[n];
  subset(bin, val, target, 0, n, closest);
  delete[] bin;
  int count = 0;
  for (int i = 0; i < n; i++)
    count += closest[i];
  int *book = new int[count];
  int j = 0;
  for (int i = 0; i < n; i++)
    if (closest[i])
      book[j++] = val[i];
  sort(book, book + count);
  for (int i = 0; i < count; i++)
    cout << book[i] << endl;
  delete[] closest;
  delete[] book;
  delete[] val;
  return 0;
}