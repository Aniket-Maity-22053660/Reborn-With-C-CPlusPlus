#include<iostream>
#include<memory>

using namespace std;

void swap(unique_ptr<int []> &ptr, int i, int j){
  int temp = ptr[i];
  ptr[i] = ptr[j];
  ptr[j] = temp;
}

void findMin(unique_ptr<int []> &ptr, int i, int &min, int num){
  if(i < num){
    if(ptr[i] < ptr[min]){
      min = i;
    }
    findMin(ptr, i + 1, min, num);
  }
}

void selectionSort(unique_ptr<int []> &ptr, int i, int num){
  if(i < num - 1){
    int min = i;
    findMin(ptr, i, min, num);
    if(min != i){
    swap(ptr, i, min);
    }
    selectionSort(ptr, i + 1, num);
  }
}

int main(){

  int num;
  cout<<"Enter total number of elements in the array: ";
  cin>>num;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"Enter the array elements:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  cout<<"Given array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  selectionSort(ptr, 0, num);
  cout<<"Sorted array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  return 0;
}
