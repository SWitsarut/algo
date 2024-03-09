#include <string.h>

#include <iostream>
using namespace std;

int f(int n, int k) {
  int mem[100][100];
  memset(mem, 0, sizeof(mem));

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j == 0 || j == 1 || i == j) {
        mem[i][j] = 1;
      } else {
        mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 2];
      }
    }
  }

  return mem[n][k];
}

int main() {
  int n = 6, k = 4;
  int ans = f(n, k);
  cout << "bottom up | " << ans << endl;

  return 0;
}