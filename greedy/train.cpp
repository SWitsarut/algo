#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Train {
 public:
  double start, end;
  Train(double start, double end) {
    this->start = start;
    this->end = end;
  }
};

bool compareTrains(const Train* a, const Train* b) { return a->end < b->end; }

int countPlatforms(vector<Train*> trains) {
  int platforms = 1;
  int maxPlatforms = 1;
  for (size_t i = 1; i < trains.size(); i++) {
    if (trains[i]->start < trains[i - 1]->end) {
      platforms++;
      maxPlatforms = max(maxPlatforms, platforms);
    } else {
      platforms = 1;
    }
  }

  return maxPlatforms;
}

int main() {
  int n;
  cin >> n;
  vector<Train*> trains(n);
  for (int i = 0; i < n; i++) {
    double start, end;
    cin >> start >> end;
    trains[i] = new Train(start, end);
  }
  sort(trains.begin(), trains.end(), compareTrains);
  int leastPlatforms = countPlatforms(trains);
  cout << leastPlatforms << endl;

  return 0;
}