#include <iostream>
#include <vector>
using namespace std;

int path(vector<vector<int>> arr, int n, int m) {
  if (n == 0 || m == 0) {
    return arr[n][m];
  } else {
    int up = 0, left = 0;
    if (n >= 0) up = arr[n][m] + path(arr, n - 1, m);
    if (m >= 0) left = arr[n][m] + path(arr, n, m - 1);
    return max(up, left);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> arr[i + 1][j + 1];
    }
  }
  cout << path(arr, n, m) << endl;
  return 0;
}