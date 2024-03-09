#include <bits/stdc++.h>
using namespace std;

int main() {
  // int n = 5;
  // int *arr = new int[n]{2, 25, 47, 16, 14};
  int arr[] = {4, 12, 13, 29, 32, 31, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; i--) {
    cout << arr[i] << " ";
  }
  cout << endl;
  int leftSum = 0;
  int rightSum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (leftSum < rightSum) {
      leftSum += arr[i];
    } else {
      rightSum += arr[i];
    }
  }
  cout << abs(leftSum - rightSum) << endl;
  return 0;
}