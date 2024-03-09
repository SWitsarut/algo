#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int calculateDistance(const vector<int>& path,
                      const vector<vector<int>>& distances) {
  int distance = 0;
  int n = path.size();

  for (int i = 0; i < n - 1; i++) {
    distance += distances[path[i]][path[i + 1]];
  }

  distance += distances[path[n - 1]][path[0]];  // Return to the starting city

  return distance;
}

int main() {
  int n;  // Number of cities
  cin >> n;

  vector<vector<int>> distances(n, vector<int>(n));

  // Read the distances between cities
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> distances[i][j];
    }
  }

  // Generate all possible permutations of cities
  vector<int> path(n);
  for (int i = 0; i < n; i++) {
    path[i] = i;
  }

  int minDistance = INT_MAX;
  vector<int> optimalPath;

  do {
    int distance = calculateDistance(path, distances);

    if (distance < minDistance) {
      minDistance = distance;
      optimalPath = path;
    }
  } while (next_permutation(path.begin() + 1, path.end()));

  // Print the optimal path and distance
  cout << "Optimal Path: ";
  for (int city : optimalPath) {
    cout << city << " ";
  }
  cout << optimalPath[0] << endl;

  cout << "Optimal Distance: " << minDistance << endl;

  return 0;
}