#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Line {
 private:
  int start, end;
  int length;

 public:
  Line(int start, int end) {
    this->start = start;
    this->end = end;
    this->length = abs(end - start);
  }
  void print() { cout << start << " " << end << endl; }
  int getStart() { return start; };
  int getEnd() { return end; };
  int getLength() { return length; }
};

bool endFirst(Line *a, Line *b) { return a->getEnd() > b->getEnd(); }
bool startFirst(Line *a, Line *b) { return a->getStart() < b->getStart(); }
bool longestFirst(Line *a, Line *b) { return a->getLength() > b->getLength(); }

bool compareDiff(pair<int, size_t> *a, pair<int, size_t> *b) {
  return a->first < b->first;
}

int main() {
  int n;
  cin >> n;
  vector<Line *> lines(n);
  for (size_t i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    lines[i] = new Line(start, end);
  }
  int pointA, pointB;
  cin >> pointA >> pointB;

  sort(lines.begin(), lines.end(), longestFirst);

  vector<Line *> selectedLine;
  for (size_t i = 0; i < lines.size(); i++) {
    if (pointA >= pointB) {
      break;
    }
    vector<pair<int, size_t> *> heuristics;
    for (size_t j = 0; j < lines.size(); j++) {
      heuristics.push_back(new pair(lines[j]->getEnd() - pointB, j));
    }
    // sort(heuristics.begin(), heuristics.end(), compareDiff);
    for (size_t k = 0; k < heuristics.size(); k++) {
      pair<int, size_t> *cur = heuristics.at(k);
      if (cur->first >= 0) {
        pointB = lines[cur->second]->getStart();
        selectedLine.push_back(lines[cur->second]);
        i--;
        break;
      }
    }
  }

  cout << selectedLine.size() << endl;
  sort(selectedLine.begin(), selectedLine.end(), startFirst);
  for (size_t i = 0; i < selectedLine.size(); i++) {
    selectedLine[i]->print();
  }

  return 0;
}