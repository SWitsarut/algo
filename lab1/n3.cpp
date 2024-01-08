#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];
  int *b = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  int max = b[0], min = arr[0];
  for (int i = 1; i < n; i++)
  {
    min = arr[i];
  }
  for (int i = 1; i < n; i++)
  {
    max = b[i];
  }

cout << "max " << max << "min " << min << endl;
int *freq = new int[max - min];
for (int i = 0; i < max - min; i++)
{
  freq[i] = 0;
}
for (int i = 0; i < n; i++)
{
  freq[arr[i] - min]++;
}
int maxFreq = freq[0];
}