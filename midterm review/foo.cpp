#include <iostream>
using namespace std;

int count = 0;

int foo(int n)
{
  count++;
  if (n == 0)
  {
    return 1;
  }
  if (n == 1)
  {
    return 2;
  }
  return foo(n - 1) * foo(n - 2);
}

int main()
{
  for (int i = 1; i < 100; i++)
  {
    foo(i);
    cout << i << " : " << count << endl;
    count = 0;
  }
  return 0;
}