#include <iostream>
using namespace std;

int tar = 10203040;

int sum(bool *bin, int *arr, int n) {
  int Sum = 0;
  for (int i = 0; i < n; i++) {
    if (bin[i]) {
      Sum += arr[i];
    }
  }
  return Sum;
}

void backtrack(bool *bin, int *arr, int k, int n, int target) {
  if (k <= n) {
    int Sum = sum(bin, arr, k);
    if (Sum < target) {
      bin[k] = true;
      backtrack(bin, arr, k + 1, n, target);
      bin[k] = false;
      backtrack(bin, arr, k + 1, n, target);
    } else if (Sum == target) {
      for (int i = 0; i < n; i++) {
        if (bin[i]) {
          cout << arr[i] << " ";
        }
      }
      cout << endl;
    }
  }
}

int main() {
  int n = 6;
  int *arr = new int[n]{1, 2, 3, 4, 5, 6};
  int target = 6;
  bool *bin = new bool[n]{false};
  backtrack(bin, arr, 0, n, target);
  delete[] arr;
  delete[] bin;
  return 0;
}
