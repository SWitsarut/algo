#include <climits>
#include <iostream>
using namespace std;

int main() {
  int n = 4;
  int graph[4][4] = {{0, 9, 10, 1},
                     {INT_MAX, 0, 1, INT_MAX},
                     {4, INT_MAX, 0, INT_MAX},
                     {INT_MAX, 2, 3, 0}};

  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {    
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
  }

  // Print the graph
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if (graph[i][j] == INT_MAX) {
        cout << "INF ";     
      } else {
        cout << graph[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}