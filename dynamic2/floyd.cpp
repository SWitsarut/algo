#include <climits>
#include <iostream>
using namespace std;

void warshall(int **arr) {
  int n = 4;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        arr[i][j] = min(arr[i][j], (arr[i][k] + arr[k][j]));
      }
    }
    cout << k+1 << endl;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << arr[i][j] << "\t";
      }
      cout << endl;
    }
    cout << endl;
  }
}

int main() {
  int **graph = new int *[4];
  for (int i = 0; i < 4; i++) {
    graph[i] = new int[4];
  }
  graph[0] = new int[4]{0, 9999, 3, 9999};
  graph[1] = new int[4]{2, 0, 9999, 9999};
  graph[2] = new int[4]{9999, 7, 0, 1};
  graph[3] = new int[4]{6, 9999, 9999, 0};

  warshall(graph);

  // Print the updated graph
  cout << "Updated Graph:" << endl;

  return 0;
}