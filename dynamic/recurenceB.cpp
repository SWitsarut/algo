#include <iostream>
#include <vector>
using namespace std;

int g(vector<int> mem, int i) {
  if (i <= 0) return 0;
  if (i <= 2) return 1;
  if (mem[i] != -1) {
    return mem[i];
  } else {
    mem[i] = g(mem, i - 1) + g(mem, i - 2) - g(mem, i - 3);
    return mem[i];
  }
}

int main() {
// top down 
  int n = 7;
  vector<int> mem(n + 1, -1);
  int ans = g(mem, n);
  cout << "n=" << n << "|" << ans << " " << endl;

// bottom up
  vector<int> bot(n + 1, -1);
  bot[0] = 0;
  bot[1] = 1;
  bot[2] = 1;
  cout << bot[0] << " " << bot[1] << " ";
  for (int i = 3; i < n + 1; i++) {
    bot[i] = bot[i - 1] + bot[i - 2] - bot[i - 3];
    cout << bot[i] << " ";
  }
  return 0;
}