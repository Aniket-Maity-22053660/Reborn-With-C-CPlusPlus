#include<iostream>
#include<memory>

using namespace std;

void printArray(unique_ptr<int []> &arr, int n){
  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" ";
  }
  putchar('\n');
}

void swap(unique_ptr<int []> &arr, int l, int r){
  int temp = arr[l];
  arr[l] = arr[r];
  arr[r] = temp;
}

void swapAlternateInArray(unique_ptr<int []> &arr, int n){
  if(n % 2 == 0){
    for(int i =  0 ; i < n - 1 ; i += 2){
      swap(arr, i, i+1);
    }
  }
  else{
    for(int i = 0 ; i < n - 2 ; i += 2){
      swap(arr, i, i+1);
    }
  }
}

int main(){
  int num;
  cout<<"Enter the number of elements you want to insert in the array: ";
  cin>>num;
  unique_ptr<int []> arr = make_unique<int []>(num);
  cout<<"Enter the elements:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element- "<<(i + 1)<<": ";
    cin>>arr[i];
  }
  cout<<"Given array: ";
  printArray(arr, num);
  swapAlternateInArray(arr, num);
  cout<<"After alternate swap: ";
  printArray(arr, num);
  return 0;
}
