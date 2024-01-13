#include <iostream>
using namespace std;

int main()
{
  int n = 5;
  int *counter = new int[100000];
  cin >> n;
  for (int i = 0; i < 100000; i++)
  {
    counter[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    int inp;
    cin >> inp;
    counter[inp - 1]++;
  }

  int count = 0;
  for (int i = 0; i < 100000; i++)
  {
    if (counter[i] > 0)
      count++;
  }
  cout << count;
  delete[] counter;
  return 0;
}