#include <iostream>
using namespace std;

/**
 * Checks if a given key is not present in the array or if it is present within
 * a range of +/- 1.
 *
 * @param array The array to search in.
 * @param size The size of the array.
 * @param key The key to check for.
 * @return True if the key is not present or within a range of +/- 1, false
 * otherwise.
 */
bool isNotIn(int *array, int size, int key) {
  for (int i = 0; i < size; i++) {
    if (array[i] == key || array[i] == key - 1 || array[i] == key + 1)
      return false;
  }
  return true;
}
int main() {
  // int size = 10;
  // int *array = new int[size]{30, 10, 8, 20, 11, 12, 25, 20, 19};
  int array[] = {15, 2, 10, 25, 20};
  int size = sizeof(array) / sizeof(array[0]);
  int maxSize = 0;
  int *maxArray = new int[size]{0};
  for (int i = 0; i < size; i++) {
    int maxVal = array[i];
    int maxIdx = i;
    for (int j = 0; j < size; j++) {
      if (array[j] > maxVal) {
        if (isNotIn(maxArray, maxSize, j)) {
          maxVal = array[j];
          maxIdx = j;
        }
      }
    }
    if (isNotIn(maxArray, maxSize, maxIdx)) maxArray[maxSize++] = maxIdx;
  }
  int sum = 0;
  for (int i = 0; i < maxSize; i++) {
    cout << maxArray[i] << " ";
    cout << array[maxArray[i]] << endl;
    sum += array[maxArray[i]];
  }
  cout << "Sum = " << sum << endl;
  return 0;
}