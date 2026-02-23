#include<iostream>
#include<memory>
#include<algorithm>

using namespace std;

void findTotalOccurrence(unique_ptr<int []> &ptr, int i, int j, int key, int &count){
  if(j > i){
    return;
  }
  int mid = i + (j - i) / 2;
  if(ptr[mid] == key){
    count++;
    j = mid - 1;
  }else if(ptr[mid] > key){
    j = mid - 1;
  }else{
    i = mid + 1;
  }
  findTotalOccurrence(ptr, i, j, key, count);
  return;
}

int main(){
  int num;
  cout<<"Enter total number of elements: ";
  cin>>num;
  int key;
  cout<<"Enter the key element: ";
  cin>>key;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"Enter the array elements:-"<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  sort(ptr.get(), ptr.get() + num);
  int count = 0;
  findTotalOccurrence(ptr, 0, num - 1, key, count);
  if(count != 0){
    cout<<"Total occurrence of "<<key<<" in the array: "<<count<<endl;
  }else{
    cout<<key<<" was not found in the array!"<<endl;
  }
  return 0;
}
