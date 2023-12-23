#include<iostream>
using namespace std;

bool isSorted(int arr[],int n,int cur=0){
  if(n==cur-1){
    return true;
  }else{
    
    return arr[cur] < arr[cur+1] && isSorted(arr,n,cur+1);
  }
}

int main(){
  // int *arr = new int[4];
  int arr[] = {1,2,4,5};
  cout<<isSorted(arr,4);
  return 0;
}
