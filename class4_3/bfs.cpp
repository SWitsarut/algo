#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
  int v;
  vector<list<int>> adj;

 public:
  Graph(int v);
  void addEdge(int v, int w);
  void bfs(int s);
  void printGraph();
};

Graph::Graph(int v) {
  this->v = v;
  adj.resize(v);
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::printGraph() {
  for (int i = 0; i < v; i++) {
    cout << "Adjacency list of vertex " << i << ": ";
    for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }
}

void Graph::bfs(int s) {
  queue<int> q;
  vector<bool> visited(v, false);
  visited[s] = true;
  q.push(s);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for (int adjacent : adj[cur]) {
      if (!visited[adjacent]) {
        visited[adjacent] = true;
        q.push(adjacent);
      }
    }
  }
  cout << endl;
}
int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.printGraph();
  g.bfs(2);
  return 0;
}