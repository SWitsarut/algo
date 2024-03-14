#include <string.h>

#include <algorithm>  // Include the <algorithm> header for std::max
#include <iostream>
#include <vector>
using namespace std;

class Item {
 public:
  int value;
  int weight;
  Item(int value, int weight) {
    this->value = value;
    this->weight = weight;
  }
};

int knap(int mem[][100], Item** items, int n, int k) {
  if (n >= 0) {
    if (mem[n][k] != -1) {
      cout << "found " << n << " " << k << " " << mem[n][k] << endl;
      return mem[n][k];
    } 
    int nottake = knap(mem, items, n - 1, k);
    int take = 0;
    if (k - items[n]->weight >= 0) {
      take = knap(mem, items, n - 1, k - items[n]->weight);
    }
    int temp = max(take + items[n]->value, nottake);
    mem[n][k] = temp;
    return temp;
  }
  return 0;
}

int main() {
  int n = 4;
  int mem[100][100];
  memset(mem, -1, sizeof(mem));
  cout << mem[2][2] << endl;
  Item** items = new Item*[n];
  items[0] = new Item(1, 1);
  items[1] = new Item(4, 3);
  items[2] = new Item(5, 4);
  items[3] = new Item(7, 5);
  cout << "ans " << knap(mem, items, n - 1, 7);
  return 0;
}