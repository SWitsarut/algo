#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node in the graph
struct Node {
  int id;
  int distance;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
  int n = graph.size();
  vector<int> distances(n, INT_MAX);
  vector<bool> visited(n, false);
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  distances[source] = 0;
  pq.push({source, 0});

  while (!pq.empty()) {
    int u = pq.top().id;
    pq.pop();

    if (visited[u]) {
      continue;
    }

    visited[u] = true;

    for (auto neighbor : graph[u]) {
      int v = neighbor.first;
      int weight = neighbor.second;

      if (distances[u] + weight < distances[v]) {
        distances[v] = distances[u] + weight;
        pq.push({v, distances[v]});
      }
    }
  }

  // Print the shortest distances from the source to all other nodes
  cout << "Shortest distances from source " << source << ":\n";
  for (int i = 0; i < n; i++) {
    cout << "Node " << i << ": " << distances[i] << "\n";
  }
}

int main() {
  // Example usage
  int n = 5; // Number of nodes
  vector<vector<pair<int, int>>> graph(n);

  // Add edges to the graph
  graph[0].push_back({1, 10});
  graph[0].push_back({4, 5});
  graph[1].push_back({2, 1});
  graph[1].push_back({4, 2});
  graph[2].push_back({3, 4});
  graph[3].push_back({2, 6});
  graph[3].push_back({0, 7});
  graph[4].push_back({1, 3});
  graph[4].push_back({2, 9});
  graph[4].push_back({3, 2});

  int source = 0; // Source node

  dijkstra(graph, source);

  return 0;
}