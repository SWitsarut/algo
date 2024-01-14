#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

void merge(int arr[], int const left, int const mid,
           int const right)
{
  int const Lstart = mid - left + 1;
  int const Rstart = right - mid;

  int *lArr = new int[Lstart], *rArr = new int[Rstart];

  for (int i = 0; i < Lstart; i++)
    lArr[i] = arr[left + i];
  for (int j = 0; j < Rstart; j++)
    rArr[j] = arr[mid + 1 + j];

  int idxLarr = 0, idxRarr = 0;
  int k = left;

  while (idxLarr < Lstart && idxRarr < Rstart)
  {
    if (lArr[idxLarr] <= rArr[idxRarr])
    {
      arr[k] = lArr[idxLarr];
      idxLarr++;
    }
    else
    {
      arr[k] = rArr[idxRarr];
      idxRarr++;
    }
    k++;
  }

  while (idxLarr < Lstart)
  {
    arr[k] = lArr[idxLarr];
    idxLarr++;
    k++;
  }

  while (idxRarr < Rstart)
  {
    arr[k] = rArr[idxRarr];
    idxRarr++;
    k++;
  }
  delete[] lArr;
  delete[] rArr;
}

void mergeSort(int *arr, int l, int r)
{
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  mergeSort(arr, 0, n - 1);
  ostringstream oss;
  for (int i = 0; i < n; i++)
  {
    oss << arr[i];
  }
  string str = oss.str();
  cout << str << endl;
  char curChar = str[0];
  char *maxChar = new char[2];
  maxChar[0] = curChar;
  maxChar[1] = '\0';
  int curCount = 1;
  int maxCount = 1;
  string reduced = "";
  reduced += curChar;
  for (int i = 1; i < str.length(); i++)
  {
    if (curChar == str[i])
    {
      curCount++;
    }
    else
    {
      if (curCount > maxCount)
      {
        delete[] maxChar;
        maxCount = curCount;
        maxChar = new char[2];
        maxChar[0] = curChar;
        maxChar[1] = '\0';
      }
      else if (curCount == maxCount)
      {
        char *temp = new char[strlen(maxChar) + 2];
        strcpy(temp, maxChar);
        strcat(temp, &curChar);
        delete[] maxChar;
        maxChar = temp;
      }
      curChar = str[i];
      reduced += curChar;
      curCount = 1;
    }
  }

  if (curCount > maxCount)
  {
    delete[] maxChar;
    maxChar = new char[2];
    maxChar[0] = curChar;
    maxChar[1] = '\0';
  }
  else if (curCount == maxCount)
  {
    char *temp = new char[strlen(maxChar) + 2];
    strcpy(temp, maxChar);
    strcat(temp, &curChar);
    delete[] maxChar;
    maxChar = temp;
  }

  int *numbers = new int[10];
  for (int i = 0; i < 10; i++)
  {
    numbers[i] = 0;
  }
  for (int i = 0; i < strlen(maxChar); i++)
  {
    int number = maxChar[i] - '0';
    numbers[number]++;
  }
  for (int i = 0; i < 10; i++)
  {
    if (numbers[i] > 0)
    {
      cout << i << " ";
    }
  }
  cout << endl;
  cout << reduced << endl;
  return 0;
}