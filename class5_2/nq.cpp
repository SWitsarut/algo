#include <iostream>
using namespace std;

int n = 4, x[4];
int count = 0;

bool btIsSafe(int row, int col)
{
  for (int i = 0; i < col; i++)
  {
    if (abs(row - i) == abs(x[i] - x[row]) || x[row] == x[i])
    {
      return false;
    }
  }
  return true;
}

bool isSafe()
{

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (abs(i - j) == abs(x[j] - x[i]) || x[i] == x[j])
      {
        return false;
      }
    }
  }
  return true;
}

void n_queen(int col)
{
  if (col == n)
  {
    count++;
    // if (isSafe())
    // {
    for (int i = 0; i < col; i++)
    {
      cout << x[i];
    }
    cout << endl;
    // }
  }
  else
  {
    for (int row = 0; row < n; row++)
    {
      x[col] = row;
      if (isSafe(row, col))
      {
        n_queen(col + 1);
      }
    }
  }
}

int main()
{
  n_queen(0);
  cout << count << endl;
  return 0;
}