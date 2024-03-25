#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int f(vector<int>& v, int n, int k, int count, vector<vector<int>>& memo) {
  if (k < 0) {
    return 0;
  };
  if (n < 0) {
    return count;
  };
  if (k == 0) {
    return 0;
  }
  if (memo[n][k] != -1) {
    return memo[n][k];
  }
  int take = 1 + f(v, n - 1, k - v[n], count, memo);
  int nottake = f(v, n - 1, k, count, memo);
  memo[n][k] = max(take, nottake);
  return memo[n][k];
}

int main() {
  int n = 5;
  vector<int> v = {1, 1, 2, 1, 3};
  int k = 5;
  vector<vector<int>> memo(n, vector<int>(k + 1, -1));
  cout << f(v, n - 1, k, 0, memo) << endl;

  return 0;
}