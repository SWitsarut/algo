#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
  int start;
  int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
  return a.end < b.end;
}

vector<Interval> intervalScheduling(const vector<Interval>& intervals) {
  vector<Interval> selectedIntervals;

  vector<Interval> sortedIntervals = intervals;
  sort(sortedIntervals.begin(), sortedIntervals.end(), compareIntervals);

  selectedIntervals.push_back(sortedIntervals[0]);

  int lastSelected = 0;
  for (int i = 1; i < sortedIntervals.size(); i++) {
    if (sortedIntervals[i].start >= selectedIntervals[lastSelected].end) {
      selectedIntervals.push_back(sortedIntervals[i]);
      lastSelected++;
    }
  }

  return selectedIntervals;
}

int main() {
  // Example usage
  vector<Interval> intervals = {{10, 12}, {9, 11}, {13, 15}};

  vector<Interval> selectedIntervals = intervalScheduling(intervals);

  cout << "Selected Intervals:\n";
  for (const auto& interval : selectedIntervals) {
    cout << "[" << interval.start << ", " << interval.end << "]\n";
  }

  return 0;
}
