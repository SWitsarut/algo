#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int Max = arr[0]; 

  for (int i = 0; i < n; i++)
  {
    int sum = arr[i]; 
    for (int j = i+1; j < n; j++)
    {
      sum += arr[j];
      Max = max(sum, Max);
    }
  }
  cout << Max << endl;
  delete[] arr; 
  return 0;
}
