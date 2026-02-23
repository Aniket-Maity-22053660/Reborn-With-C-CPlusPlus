#include<iostream>
#include<memory>

using namespace std;

void reverseArray(unique_ptr<int []> &ptr, int i, int j){
  if(i < j){
    int temp = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = temp;
    reverseArray(ptr, i + 1, j - 1);
  }
}

void rotateArray(unique_ptr<int []> &ptr, int num, int index){
  reverseArray(ptr, 0, num - 1);
  int num1 = num - index - 1;
  reverseArray(ptr, 0, num1 - 1);
  reverseArray(ptr, num1, num - 1);
}

int main(){
  int num;
  cout<<"Enter the total number of elements in the array: ";
  cin>>num;
  int index;
  cout<<"Enter the breaking index: ";
  cin>>index;
  cout<<"Enter the elements in the array:-"<<endl;
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
  rotateArray(ptr, num, index);
  cout<<"Rotated array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  return 0;
}
