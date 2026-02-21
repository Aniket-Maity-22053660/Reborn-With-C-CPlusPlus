#include<iostream>
#include<memory>

using namespace std;

int findUnique(unique_ptr<int []> &ptr, int num){
  int num1 = ptr[0];
  for(int i = 1 ; i < num ; i++){
    num1 = num1 ^ ptr[i];
  }
  return num1;
}

int main(){

  int num;
  cout<<"Enter the number of elements you want to insert in the array: ";
  cin>>num;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"In this problem every number in a particular range must occurs twice except one unique number and we have to find that unique number:- "<<endl;
  cout<<"Enter the the numbers:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  int ans = findUnique(ptr, num);
  cout<<"Unique number of the array: "<<ans<<endl;
  return 0;
}
