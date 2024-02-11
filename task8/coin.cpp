#include <bits/stdc++.h>

#include <climits>
using namespace std;

int count = 0;

int sum(bool *bin, int *arr, int n) {
  int Sum = 0;
  for (int i = 0; i < n; i++) {
    if (bin[i]) {
      Sum += arr[i];
    }
  }
  return Sum;
}

bool check(bool *bin, int n) {
  if (n <= 1) return true;
  if (bin[n - 1] && bin[n - 2]) return false;
  return true;
}

int backtrack(bool *bin, int *arr, int k, int n) {
  bool valid = check(bin, k);
  if (valid) {
    if (k < n) {
      bin[k] = true;
      int left = backtrack(bin, arr, k + 1, n);
      bin[k] = false;
      int right = backtrack(bin, arr, k + 1, n);
      return max(left, right);
    } else {
      return sum(bin, arr, k);
    }
  }
  return INT_MIN;
}

int main() {
  int n = 10;
  int *arr = new int[10]{30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
  bool *bin = new bool[n];
  memset(bin, false, n);
  int result = backtrack(bin, arr, 0, n);
  cout << "Maximum sum: " << result << endl;
  delete[] arr;
  delete[] bin;
  return 0;
}
