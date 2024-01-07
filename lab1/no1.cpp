#include <iostream>
using namespace std;

class MaxHeap {
public:
  int tail = -1;
  int *arr = nullptr;

  MaxHeap(int size) {
    this->arr = new int[size];
    this->tail = -1;
  }
  ~MaxHeap() { delete arr; }

  void insert(int num) {
    arr[++tail] = num;
    int at = tail;
    while (at > 0 && arr[at] < arr[(at - 1) / 2]) {
      int temp = arr[at];
      arr[at] = arr[(at - 1) / 2];
      arr[(at - 1) / 2] = temp;
      at = (at - 1) / 2;
    }
  }

  int pop() {
    int temp = arr[0];
    arr[0] = arr[tail--];
    int at = 0;
    while (true) {
      int biggest = at;
      int Lidx = at * 2 + 1;
      int Ridx = at * 2 + 2;

      if (Lidx < tail + 1 && arr[Lidx] < arr[biggest]) {
        biggest = Lidx;
      }

      if (Ridx < tail + 1 && arr[Ridx] < arr[biggest]) {
        biggest = Ridx;
      }
      if (biggest == at) {
        break;
      } else {
        int temp = arr[at];
        arr[at] = arr[biggest];
        arr[biggest] = temp;
        at = biggest;
      }
    }
    return temp;
  }

  void print() {
    for (int i = 0; i < tail + 1; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main(int argc, char *argv[]) {
  int n = 0;
  cin >> n;
  MaxHeap *heap = new MaxHeap(n);
  for (int i = 0; i < n; i++) {
    int num = 0;
    cin >> num;
    heap->insert(num);
  }
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = heap->pop();
  }
  delete heap;

  int Old = arr[0];
  int set = 1;
  for (int i = 1; i < n; i++) {
    int watch = arr[i];
    if (watch - 1 != Old) {
      set++;
    }
    Old = watch;
  }
  cout << set << endl;
  return 0;
}
