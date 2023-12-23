#include <iostream>
#include <string>
using namespace std;

class Node {
public:
  int key = 0;
  int freq = 0;
  Node(int key) {
    this->key = key;
    freq = 1;
  }
  string toString() { return to_string(key) + ": " + to_string(freq); }
};

class Wrap {
public:
  Node **arr = nullptr;
  int n = 0;
  int tail = -1;
  Wrap(int n) {
    this->n = n;
    arr = new Node *[n];
    tail = -1;
  }

  ~Wrap() {
    for (int i = 0; i <= tail; ++i) {
      delete arr[i];
    }
    delete[] arr;
  }

  void add(int key) {
    bool contained = false;
    int idx = 0;
    for (int i = 0; i <= tail; i++) {
      if (arr[i]->key == key) {
        contained = true;
        idx = i;
        break;
      }
    }
    if (!contained) {
      arr[++tail] = new Node(key);
    } else {
      arr[idx]->freq++;
    }
  }

  void print() {
    for (int i = 0; i <= tail; i++) {
      cout << arr[i]->toString() << endl;
    }
  } 
  int getDifferent(){
    int max = arr[0]->freq;
    int min = arr[0]->freq;
    int size = tail+1;

    for ( int i =1;i<size;i++ ) {
      int watchingFreq = arr[i]->freq;
      if(watchingFreq > max){
        max = watchingFreq;
      }
      if(watchingFreq<min){
        min =watchingFreq;
      }
    }
    return max-min;
  }
};

int main() {
  int n = 0;
  cin >> n;
  Wrap *arr = new Wrap(n);
  for (int i = 0; i < n; i++) {
    int key = 0;
    cin >> key;
    arr->add(key);
  }

  cout<<arr->getDifferent()<<endl;

  return 0;
}
