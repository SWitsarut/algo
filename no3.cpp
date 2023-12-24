#include <iostream>
using namespace std;

void getInput(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int inRange(int start, int targetTime, int end) {
  return targetTime >= start && targetTime <= end ? 1 : 0;
}

int main() {
  int n = 5;
  // cin>>n;
  int *arr = new int[n]{1, 2, 10, 12, 5};
  int *brr = new int[n]{10, 10, 12, 18, 10};

  int minTime = arr[0], maxTime = brr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < minTime) {
      minTime = arr[i];
    }
    if (brr[i] > maxTime) {
      maxTime = brr[i];
    }
  }

  int maxPresent = 0;
  int idx = -1;
  for (int i = minTime; i <= maxTime; i++) {
    int curPresent = 0;
    for (int j = 0; j < n; j++) {
      curPresent += inRange(arr[j], i, brr[j]);
    }
    if (curPresent > maxPresent) {
      maxPresent = curPresent;
      idx = i;
    }
  }
  cout << idx << " " << maxPresent << endl;
  return 0;
}
