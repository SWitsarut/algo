#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int max = arr[0], min = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  cout<<"max "<<max<<"min "<<min<<endl;
  int *freq = new int[max - min];
  for (int i = 0; i < max - min; i++)
  {
    freq[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    freq[arr[i] - min]++;
    cout << arr[i] << "," << freq[arr[i] - min] << "|";
  }
  int maxFreq=freq[0];
  int minFreq=freq[0];
  for( int i=1;i<max-min;i++){
    if (freq[i] > maxFreq)
    {
      maxFreq = freq[i];
    }
    if (freq[i] < minFreq)
    {
      minFreq = freq[i];
    }
  }
  cout<<maxFreq-minFreq<<endl;
  return 0;
}