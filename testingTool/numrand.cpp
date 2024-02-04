#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    cerr << "Usage: " << argv[0] << " [array_size]" << endl;
    return 1;
  }

  int n;
  if (argc == 2)
  {
    n = stoi(argv[1]);
  }
  else
  {
    // cout << "Enter the array size: ";
    cin >> n;
  }

  int *arr = new int[n];
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 100;
  }

  // cout << "Random Integer Array:\n";
  printArray(arr, n);

  delete[] arr;
  return 0;
}
