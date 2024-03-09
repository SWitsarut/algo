#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  double capacity;
  cin >> n >> capacity;
  vector<double> itemsW(n);
  vector<double> itemsV(n);
  for (int i = 0; i < n; i++) {
    cin >> itemsW[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> itemsV[i];
  }

  vector<int> itemIndices(n);
  for (int i = 0; i < n; i++) {
    itemIndices[i] = i;
  }

  sort(itemIndices.begin(), itemIndices.end(), [&](int a, int b) {
    return itemsV[a] / itemsW[a] > itemsV[b] / itemsW[b];
  });

  double curCap = 0;
  double val = 0;
  vector<double> fictional(n, 0);

  for (int i = 0; i < n; i++) {
    if (curCap + itemsW[itemIndices[i]] <= capacity) {
      curCap += itemsW[itemIndices[i]];
      val += itemsV[itemIndices[i]];
      fictional[itemIndices[i]] = 1;
    } else {
      double remainCap = capacity - curCap;
      remainCap /= itemsW[itemIndices[i]];
      val += remainCap * itemsV[itemIndices[i]];
      curCap += remainCap;
      fictional[itemIndices[i]] += remainCap;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(2) << fictional[i] << " ";
  }
  cout << endl;
  cout << fixed << setprecision(2) << val;
  return 0;
}