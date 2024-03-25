#include <iostream>
#include <vector>
using namespace std;

int cnk(int n, int k, vector<vector<int>>& memo) {
  if (k == 0 || k == n) {
    return 1;
  }
  if (memo[n][k] != -1) {
    return memo[n][k];
  }
  memo[n][k] = cnk(n - 1, k - 1, memo) + cnk(n - 1, k, memo);
  return memo[n][k];
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
  cout << cnk(n, k, memo) << endl;
  return 0;
}