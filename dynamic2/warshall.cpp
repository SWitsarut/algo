#include <iostream>
using namespace std;

void warshall(bool **arr) {
  // Implementing the Warshall algorithm
  int n = 4;  // Assuming the size of the matrix is 4x4

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
      }
    }

    cout << k << endl;
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
  bool **graph = new bool *[4];
  // for (int i = 0; i < 4; i++) {
  //   graph[i] = new bool[4];
  // }
  graph[0] = new bool[4]{0, 0, 1, 0};
  graph[1] = new bool[4]{1, 0, 0, 1};
  graph[2] = new bool[4]{0, 0, 0, 0};
  graph[3] = new bool[4]{0, 1, 0, 0};

  warshall(graph);

  // Print the updated graph
  cout << "Updated Graph:" << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}