#include <iostream>
using namespace std;

int maxSum(int *arr,int n){
  if (n==1){
    return arr[0];
  }else{
    int m = n/2;
    int L = maxSum(arr,m);
  }

}

int main()
{

  return 0;
}