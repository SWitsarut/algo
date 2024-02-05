#include <iostream>
using namespace std;
void Subset2(int x[], int k, int n)
{
  // check(x[1....k])
  // Print
  int j;
  for (int i = 1; i <= k; i++)
  {
    cout << x[i];
  }
  cout << endl;
  if (k == 0)
  {
    j = 1;
  }
  else
  {
    j = x[k] + 1;
  }
  for (int i = j; i <= n; i++)
  {
    x[k + 1] = i;
    Subset2(x, k + 1, n);
  }
}
int main()
{
  int array_suea[4] = {5, 6, 7, 99};
  Subset2(array_suea, 0, sizeof(array_suea) / sizeof(array_suea[0]));
  return 0;
}