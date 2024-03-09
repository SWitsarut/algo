#include <bits/stdc++.h>

#include <climits>
using namespace std;

bool isNotIntersect(bool *bin, int n) {
  if (n <= 1) return true;
  if (bin[n - 2] == bin[n - 1]) return false;
  return true;
}

int subset(bool *bin, int *arr, int k, int n) {
  bool check = isNotIntersect(bin, k);
  if (k == n) {
    if (!check) return INT_MAX;
    int momoi = 0;
    int midori = 0;
    for (int i = 0; i < n; i++) {
      if (bin[i]) {
        momoi += arr[i];
      } else {
        midori += arr[i];
      }
    }
    // for (size_t i = 0; i < n; i++) {
    //   cout << bin[i] << " ";
    // }
    int diff = abs(momoi - midori);
    // cout << "\t" << diff << endl;
    return diff;
  } else {
    if (check || k % 2 == 1) {
      bin[k] = true;
      int left = subset(bin, arr, k + 1, n);
      bin[k] = false;
      int right = subset(bin, arr, k + 1, n);
      return min(left, right);
    }
    return INT_MAX;
  }
}

int main() {
  int n = 4 * 2;
  int *arr = new int[n]{3, 5, 7, 11, 8, 8, 2, 9};
  bool *bin = new bool[n];
  memset(bin, false, n);
  int minDiff = subset(bin, arr, 0, n);
  cout << minDiff << endl;

  delete[] arr;
  delete[] bin;

  return 0;
}