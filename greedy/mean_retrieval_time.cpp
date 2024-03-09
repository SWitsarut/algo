#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double calculate(const vector<double>& arr) {
  double sum = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      sum += arr[j];
    }
  }
  return sum / n;
}

int main() {
  int n;
  cin >> n;
  vector<double> sizes(n);
  for (int i = 0; i < n; i++) {
    cin >> sizes[i];
  }
  sort(sizes.begin(), sizes.end());
  for (int i = 0; i < n; i++) {
    cout << sizes[i] << " ";
  }
  cout << fixed << setprecision(2) << calculate(sizes);
  return 0;
}
 
// 1 2 3
// (1 + 3 + 6 )/n<( 3 + 5 + 6)/n
// t1 + (t1+t2) + (t1+t2+t3) < t3 + (t3+t2) + (t3+t2+t1n)
// 3t1 + 2t2 + t3 < t1+ 2t2 + 3t3
// 3t1 + t3 < t1+ 3t3
// t1 < t3 == true
