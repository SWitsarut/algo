#include <iostream>
#include "intervalScheduling.cpp"

int main() {
  Interval intervals[] = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}};
  int size = sizeof(intervals) / sizeof(intervals[0]);

  Interval* selectedIntervals = intervalScheduling(intervals, size);

  std::cout << "Selected Intervals:\n";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << selectedIntervals[i].start << ", "
              << selectedIntervals[i].end << "]\n";
  }

  delete[] selectedIntervals;

  return 0;
}