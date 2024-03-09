#include <string.h>

#include <iostream>
using namespace std;

int f(int mem[][100], int n, int k) {
  if (n >= k) {
    if (k == 0) return 1;
    if (k == 1) return 1;
    if (n == k) return 1;
    if (mem[n][k] != -1) {
      return mem[n][k];
    } else {
      mem[n][k] = f(mem, n - 1, k) + f(mem, n - 1, k - 2);
      return mem[n][k];
    }
  }
  return 0;
}

int main() {
  int mem[100][100];
  memset(mem, -1, sizeof(mem));
  int n = 6, k = 4;
  int ans = f(mem, n, k);
  cout << "top down |" << ans << endl;
  // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  return 0;
}