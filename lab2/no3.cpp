#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n = 0;
  cin >> n;
  int *uni = new int[n * 2];
  int unisize = 0;
  int *ins = new int[n];
  int inssize = 0;

  for (int i = 0; i < n; i++) {
    int temp = 0;
    cin >> temp;
    bool found = false;
    for (int j = 0; j < unisize; j++) {
      if (temp == uni[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      uni[unisize] = temp;
      unisize++;
    }
  }

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    bool found = false;
    for (int j = 0; j < unisize; j++) {
      if (temp == uni[j]) {
        ins[inssize] = temp;
        inssize++;
        found = true;
        break;
      }
    }
    if (!found) {
      uni[unisize] = temp;
      unisize++;
    }
  }
  for (int i = 0; i < inssize - 1; i++) {
    cout << ins[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < unisize; i++) {
    cout << uni[i] << " ";
  }
  cout << endl;
  delete  [] uni;
  delete [] ins;
  return 0;
}
