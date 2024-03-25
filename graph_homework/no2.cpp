#include <iostream>
using namespace std;

void dfs(int** graph, int* visited, int current, int n) {
  visited[current] = 1;
  for (size_t i = 0; i < n; i++) {
    if (graph[current][i] == 1 && visited[i] == 0) {
      dfs(graph, visited, i, n);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int** graph = new int* [n] {};
  for (size_t i = 0; i < n; i++) {
    graph[i] = new int[n]{};
  }

  for (size_t i = 0; i < n; i++) {
    int start;
    cin >> start;
    int target = 1;
    while (target != 0) {
      cin >> target;
      if (target != 0) {
        graph[start - 1][target - 1] = 1;
      }
    }
  }

  // for (size_t i = 0; i < n; i++) {
  //   for (size_t j = 0; j < n; j++) {
  //     cout << graph[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int k;
  cin >> k;
  for (size_t i = 0; i < k; i++) {
    int start;
    cin >> start;
    int* visited = new int[n]{};
    dfs(graph, visited, start - 1, n);
    for (size_t j = 0; j < n; j++) {
      if (!visited[j]) cout << j + 1 << " ";
    }
    cout << endl;
    delete[] visited;
  }

  return 0;
}