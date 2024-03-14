#include <iostream>
using namespace std;

int c(int n, int k) {
  if (k == 0) return 1;
  if (n == k) return 1;
  return c(n - 1, k - 1) + c(n - 1, k);
}

int main() {
  int n = 4;
  int k = 2;
  cout << c(n, k) << endl;
  return 0;
}