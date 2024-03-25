#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> memo) {
  if (n <= 1) {
    return 1;
  }
  if (memo[n] > 0) {
    return memo[n];
  }
  memo[n] = (3 * fib(n - 1, memo)) + fib(n - 2, memo);
  return memo[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> memo(n + 1, -1);
  cout << fib(n - 1, memo) << endl;
  return 0;
}