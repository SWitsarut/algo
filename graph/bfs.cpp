#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal
void bfs(vector<vector<int>>& graph, int startNode) {
  int numNodes = graph.size();
  vector<bool> visited(numNodes, false); // Track visited nodes
  queue<int> q; // Queue for BFS traversal

  // Mark the start node as visited and enqueue it
  visited[startNode] = true;
  q.push(startNode);

  while (!q.empty()) {
    int currentNode = q.front();
    q.pop();
    cout << currentNode << " ";

    // Enqueue all adjacent nodes of the current node
    for (int i = 0; i < graph[currentNode].size(); i++) {
      int adjacentNode = graph[currentNode][i];
      if (!visited[adjacentNode]) {
        visited[adjacentNode] = true;
        q.push(adjacentNode);
      }
    }
  }
}

int main() {
  // Create a graph
  int numNodes = 6;
  vector<vector<int>> graph(numNodes);

  // Add edges to the graph
  graph[0] = {1, 2};
  graph[1] = {0, 2, 3};
  graph[2] = {0, 1, 3, 4};
  graph[3] = {1, 2, 4, 5};
  graph[4] = {2, 3, 5};
  graph[5] = {3, 4};

  // Perform BFS traversal starting from node 0
  cout << "BFS traversal: ";
  bfs(graph, 0);

  return 0;
}