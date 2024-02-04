#include <iostream>
using namespace std;

int count = 0;

int dacPow(int base, int n)
{
  if (n == 0)
  {
    return 1;
  }
  if (n == 1)
  {
    return base;
  }
  int newN = n / 2;
  count++;
  return dacPow(base, newN) * dacPow(base, n - newN);
}
int main()
{
  int base = 2;
  int n = 5;
  cin >> base;
  cin >> n;
  cout << dacPow(base, n) << " " << count - 1 << endl;
  return 0;
}
