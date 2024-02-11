#include <bits/stdc++.h>

using namespace std;

int Sum(bool *bin, int *arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (bin[i]) sum += arr[i];
  }
  return sum;
}

int count(bool *bin, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += bin[i];
  }
  return sum;
}

void backtrack(bool *bin, int *arr, bool *take, int &max, int k, int n,
               int target) {
  if (k < n) {
    int sum = Sum(bin, arr, k - 1);
    if (sum <= target) {
      bin[k] = true;
      backtrack(bin, arr, take, max, k + 1, n, target);
      bin[k] = false;
      backtrack(bin, arr, take, max, k + 1, n, target);
    }
  } else {
    int _count = count(bin, n);
    if (_count >= 3) {
      int sum = Sum(bin, arr, n);
      if (sum <= target && sum > max) {
        max = sum;
        memcpy(take, bin, n);
      }
    }
  }
}

int main() {
  int n = 8;
  int cval = 600;
  int *books = new int[n]{136, 411, 211, 200, 275, 189, 232, 375};
  bool *take = new bool[n];
  int max = 0;
  backtrack(new bool[n]{false}, books, take, max, 0, n, cval);
  if (count(take, n) > 0) {
    for (size_t i = 0; i < n; i++) {
      if (take[i]) cout << books[i] << endl;
    }
  } else {
    cout << 0 << endl;
    cout << 0 << endl;
    cout << 0 << endl;
  }

  return 0;
}