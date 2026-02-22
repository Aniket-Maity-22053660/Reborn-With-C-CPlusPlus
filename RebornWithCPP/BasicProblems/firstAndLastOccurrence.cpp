#include<iostream>
#include<memory>
#include<utility>
#include<algorithm>

using namespace std;

void findFirstOccurrence(unique_ptr<int []> &ptr, int i, int j, int key, int &first){
  if(j < i){
    return;
  }
  int mid = i + (j - i) / 2;
  if(ptr[mid] == key){
    first = mid;
    j = mid - 1;
  }else if(ptr[mid] > key){
    j = mid - 1;
  }else{
    i = mid + 1;
  }
  findFirstOccurrence(ptr, i, j, key, first);
}

void findLastOccurrence(unique_ptr<int []> &ptr, int i, int j, int key, int &last){
  if(j < i){
    return;
  }
  int mid = i + (j - i) / 2;

  if(ptr[mid] == key){
    last = mid;
    i = mid + 1;
  }else if(ptr[mid] > key){
    j = mid - 1;
  }else{
    i = mid  + 1;
  }
  findLastOccurrence(ptr, i, j, key, last);
}

pair<int, int> findFirstAndLastOccurrence(unique_ptr<int []> &ptr, int i, int j, int key){

  int first = -1;
  int last = -1;
  findFirstOccurrence(ptr, i, j, key, first);
  findLastOccurrence(ptr, i, j, key, last);
  return {first, last};
}

int main(){
  int num;
  cout<<"Enter the number of elements in the array: ";
  cin>>num;
  cout<<"Enter the key element: ";
  int key;
  cin>>key;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"Enter the elements of the array:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  sort(ptr.get(), ptr.get() + num);
  cout<<"Given array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  pair<int, int> ans = findFirstAndLastOccurrence(ptr, 0, num - 1, key);
  if(ans.first != -1){
    cout<<"First occurrence of "<<key<<": "<<ans.first<<endl;
    cout<<"Last occurrence of "<<key<<": "<<ans.second<<endl;
  }else{
    cout<<key<<" was not found in the array!"<<endl;
  }
  return 0;
}
