#include <iostream>
using namespace std;

float avg(float* arr, int n) {
  if (n == 1) {
    cout << arr[0] << endl;
    return arr[0];
  } else {
    float now = (avg(arr, n - 1) * (n - 1) + arr[n - 1]) / n;
    cout << now << endl;
    return n
  }
}
int main() {
  int n = 4;
  float* arr = new float[n]{2, 3, 5, 6};
  float ans = avg(arr, 4);
  cout << "top down ";
  cout << ans << endl;

  cout << endl << "bottom up" << endl;
  float Avg = arr[0];
  cout << Avg << endl;
  for (int i = 1; i < n; i++) {
    Avg = (i * Avg + arr[i]) / (i + 1);
    cout << Avg << endl;
  }
  return 0;
}