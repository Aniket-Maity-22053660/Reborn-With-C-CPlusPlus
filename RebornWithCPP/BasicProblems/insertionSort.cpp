#include<iostream>
#include<memory>

using namespace std;

void rightShift(unique_ptr<int []> &ptr, int num, int key){
  if(num > 0){
    if(ptr[num - 1] > key){
      ptr[num] = ptr[num - 1];
    }else{
      ptr[num] = key;
      return;
    }
    rightShift(ptr, num - 1, key);
  }
  if(num == 0){
    ptr[0] = key;
  }
}

void insertionSort(unique_ptr<int []> &ptr, int i, int num){
  if(i < num){
    int key = ptr[i];
    rightShift(ptr, i, key);
    insertionSort(ptr, i + 1, num);
  }
}

int main(){
  int num;
  cout<<"Enter the total number of array elements: ";
  cin>>num;
  cout<<"Enter the array elements:- "<<endl;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  cout<<"Given array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  insertionSort(ptr, 1, num);
  cout<<"Sorted array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  return 0;
}
