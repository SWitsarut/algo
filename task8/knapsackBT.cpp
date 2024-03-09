#include <climits>
#include <iostream>

using namespace std;

int count = 0;
class Item {
 public:
  int weight;
  int value;
  Item(int weight, int value) {
    this->weight = weight;
    this->value = value;
  }
};

int sumweight(bool *bin, Item **items, int n) {
  int sum = 0;
  for (size_t i = 0; i < n; i++)
    if (bin[i]) sum += items[i]->weight;
  return sum;
}

int sumvalue(bool *bin, Item **items, int n) {
  int sum = 0;
  for (size_t i = 0; i < n; i++)
    if (bin[i]) sum += items[i]->value;
  return sum;
}

int mostexpensive(bool *bin, Item **items, int limit, int k, int n) {
  count++;
  if (k == n) {
    int sumw = sumweight(bin, items, n);
    if (sumw <= limit) {
      int sumv = sumvalue(bin, items, n);
      for (int i = 0; i < n; i++) {
        if (bin[i]) {
          cout << "1";
        } else {
          cout << "0";
        }
      }
      cout << "\t󰒠wi =\t" << sumw << "\t󰒠vi =\t" << sumv << endl;
      return sumv;
    } else {
      return INT_MIN;
    }
  } else {
    bin[k] = false;
    int left = INT_MIN, right = INT_MIN;
    if (sumweight(bin, items, k) <= limit) {
      left = mostexpensive(bin, items, limit, k + 1, n);
    }
    bin[k] = true;
    if (sumweight(bin, items, k) <= limit) {
      right = mostexpensive(bin, items, limit, k + 1, n);
    }

    return max(left, right);
  }
}

int main() {
  int n = 4;
  Item *items[n];
  items[0] = new Item(2, 2);
  items[1] = new Item(5, 7);
  items[2] = new Item(4, 4);
  items[3] = new Item(12, 8);

  int targetweight = 18;
  bool *bin = new bool[n]{false};
  int maxval = mostexpensive(bin, items, targetweight, 0, n);
  cout << "Maximum value within the weight limit: " << maxval << endl;
  cout << "does " << count << " time" << endl;

  for (int i = 0; i < n; ++i) {
    delete items[i];
  }

  delete[] bin;

  return 0;
}
