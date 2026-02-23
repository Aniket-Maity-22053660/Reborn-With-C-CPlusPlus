#include<iostream>
#include<memory>
#include<algorithm>

using namespace std;

void findPeak(unique_ptr<int []> &ptr, int i, int j, int &ans){
  if(j <= i){
    ans = i;
    return;
  }
  int mid = i + (j - i) / 2;
  if(ptr[mid] < ptr[mid + 1]){
    i = mid + 1;
  }else{
    j = mid;
  }
  findPeak(ptr, i, j, ans);
}

int main(){
  int num;
  cout<<"Enter total number of elements in the array: ";
  cin>>num;
  cout<<"Enter the elements in the array:-"<<endl;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<i+1<<": ";
    cin>>ptr[i];
  }
  //sort(ptr.get(), ptr.get() + num);
  cout<<"Given array: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  int ans = -1;
  findPeak(ptr, 0, num - 1, ans);
  cout<<"Peak of the mountain array: "<<ptr[ans]<<endl;
  return 0;
}
