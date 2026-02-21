#include<iostream>
#include<memory>
#include<map>
#include<set>

using namespace std;

void findDuplicates(unique_ptr<int []> &ptr, int num){

  //unique_ptr<int []> ptr1 = make_unique<int []>(num);
  map<int, int> mp;
  set<int> st;
  set<int> ans;
  for(int i = 0 ; i < num ; i++){
    mp[ptr[i]] = mp[ptr[i]] + 1;
  }
  int k = 0;
  for(int i = 0 ; i < num ; i++){
    if(st.count(ptr[i])){
      //st.insert(ptr[i]);
      ans.insert(ptr[i]);
    }else{
      st.insert(ptr[i]);
    }
  }
  if(ans.empty()){
    cout<<"Array has no duplicate elements!"<<endl;
  }else{
    set<int>::iterator itr;
    cout<<"Duplicate elements in the array: ";
    for(itr = ans.begin() ; itr != ans.end() ; itr++){
      cout<<*itr<<" ";
    }
    putchar('\n');
  }
}

int main(){
  int num;
  cout<<"Enter the number of elements ypu want to insert in the array: ";
  cin>>num;

  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"In this problem we are required to find the duplicate elements:- "<<endl;
  cout<<"Enter the elements in the array:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  //unique_ptr<int []> ptr1 = make_unique<int []>(num);
  findDuplicates(ptr, num);
  return 0;
}
