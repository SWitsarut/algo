#include <iostream>
#include <vector>
using namespace std;

void DFS(int, vector<int>&);
int visited[8], n = 8;

int G[8][8] = {{0, 1, 1, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 0, 0},
               {1, 0, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 0, 0, 0, 0, 1},
               {0, 0, 0, 1, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}};

int main() {
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
  }

  vector<int> path;
  DFS(0, path);

  return 0;
}

void DFS(int i, vector<int>& path) {
  path.push_back(i);
  visited[i] = 1;

  if (i == 7) {
    cout << "Path to 7: ";
    for (int j = 0; j < path.size(); j++) {
      cout << path[j] << " ";
    }
    cout << endl;
  }

  for (int j = 0; j < n; j++) {
    if (!visited[j] && G[i][j] != 0) {
      DFS(j, path);
    }
  }

  visited[i] = 0;
  path.pop_back();
}