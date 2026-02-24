#include<iostream>
#include<memory>
#include<algorithm>

using namespace std;

void printArray(unique_ptr<int []> &ptr, int num){
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
}

void merge(unique_ptr<int []> &ptr1, unique_ptr<int []> &ptr2, int &i, int &j,int &k, int num1, int num2, unique_ptr<int []> &ans){
  if(i < num1 && j < num2){
    if(ptr1[i] < ptr2[j]){
      ans[k++] = ptr1[i++];
    }else{
      ans[k++] = ptr2[j++];
    }
    merge(ptr1, ptr2, i, j, k, num1, num2, ans);
  }
}

void merge1(unique_ptr<int []> &ptr1, int i, int k, int num1, unique_ptr<int []> &ans){
  if(i < num1){
    ans[k] = ptr1[i];
    merge1(ptr1, (i + 1), k + 1, num1, ans);
  }
}

void merge2(unique_ptr<int []> &ptr2, int j, int k, int num2, unique_ptr<int []> &ans){
  if(j < num2){
    ans[k] = ptr2[j];
    merge2(ptr2, j + 1, k + 1, num2, ans);
  }
}

void merge2SortedArr(unique_ptr<int []> &ptr1, unique_ptr<int []> &ptr2, int i, int j, int num1, int num2, unique_ptr<int []> &ans){
  int k = 0;
  merge(ptr1, ptr2, i, j, k, num1, num2, ans);
  merge1(ptr1, i, k, num1, ans);
  merge2(ptr2, j, k, num2, ans);
}

int main(){
  int num1, num2;
  cout<<"Enter the total number of elements for array - 1: ";
  cin>>num1;
  cout<<"Enter the total number of elements for array - 2: ";
  cin>>num2;
  cout<<"Enter the elements for array - 1:-"<<endl;
  unique_ptr<int []> ptr1 = make_unique<int []>(num1);
  unique_ptr<int []> ptr2 = make_unique<int []>(num2);
  unique_ptr<int []> ans = make_unique<int []>(num1 + num2);
  for(int i = 0 ; i < num1 ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr1[i];
  }
  cout<<"Enter the elements for array - 2:- "<<endl;
  for(int i = 0 ; i < num2 ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr2[i];
  }
  sort(ptr1.get(), ptr1.get() + num1);
  sort(ptr2.get(), ptr2.get() + num2);
  cout<<"Given array1: ";
  printArray(ptr1, num1);
  cout<<"Given array2: ";
  printArray(ptr2, num2);
  merge2SortedArr(ptr1, ptr2, 0, 0, num1, num2, ans);
  cout<<"Merged array: ";
  printArray(ans, num1 + num2);
}
