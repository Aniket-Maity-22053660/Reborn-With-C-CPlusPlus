#include<iostream>
#include<memory>

using namespace std;

bool checkSorted(unique_ptr<int []> &ptr, int i, int num){
  if(i < num - 1){
    if(ptr[i] > ptr[i + 1]){
      return false;
    }
    return checkSorted(ptr, i + 1, num);
  }
  return true;
}

int main(){
  int num;
  cout<<"Enter the size of the array: ";
  cin>>num;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"Enter the array elements:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<i+1<<": ";
    cin>>ptr[i];
  }
  bool ans = checkSorted(ptr, 0, num);
  if(ans){
    cout<<"Array is sorted in non-decreasing order!"<<endl;
  }else{
    cout<<"Array is not sorted!"<<endl;
  }
  return 0;
}
