#include <climits>
#include <iostream>
using namespace std;

// หาจำนวนเส้นทางที่สั้นที่สุดจากจุดเริ่มต้นไปยังจุดปลายทาง

int dfs(int** graph, int* visited, int current, int target, int count, int n) {
  if (current == target) {
    return count;
  }

  visited[current] = 1;

  int shortest = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (graph[current][i] == 1 && visited[i] == 0) {
      int pathLength = dfs(graph, visited, i, target, count + 1, n);
      shortest = min(shortest, pathLength);
    }
  }

  visited[current] = 0;
  return shortest;
}

int main() {
  int n;
  cin >> n;
  int** graph = new int*[n];
  for (size_t i = 0; i < n; i++) {
    graph[i] = new int[n]{};
  }
  for (size_t i = 0; i < n; i++) {
    int start;
    cin >> start;
    int opt = 0;
    while (opt >= 0) {
      cin >> opt;
      if (opt > 0) {
        graph[opt][start] = 1;
      }
    }
  }

  int start, target;
  cin >> start >> target;

  int* visited = new int[n]{};
  int shortest = dfs(graph, visited, start, target, 0, n);
  cout << shortest << endl;
  return 0;
}
