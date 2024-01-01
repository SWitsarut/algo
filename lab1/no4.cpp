#include <iostream>
using namespace std;

bool isSorted(int *arr, int n, int cur = 0) {
  if (cur == n - 1) {
    return true;
  } else {
    return arr[cur] <= arr[cur + 1] && isSorted(arr, n, cur + 1);
  }
}

int main() {
  int n =0;
  cin>>n;
  int *arr = new int[n];
  for(int i =0;i<n;i++){
    
  }
  cout << isSorted(arr, 4);
  delete[] arr;
  return 0;
}
