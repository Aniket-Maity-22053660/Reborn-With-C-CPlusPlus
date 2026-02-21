#include<iostream>
#include<memory>
#include<map>
#include<set>

using namespace std;

void detectDuplicateOccurrence(unique_ptr<int []> &ptr, int num){
  map<int, int> mp;
  set<int> st;
  set<int> ans;
  for(int i = 0 ; i < num ; i++){
    mp[ptr[i]] = mp[ptr[i]] + 1;
  }
  map<int, int>::iterator itr;
  for(itr = mp.begin() ; itr != mp.end() ; itr++){
    if(st.count(itr->second)){
      for(int i = 0 ; i < num ; i++){
	if(mp[ptr[i]] == itr->second){
	  ans.insert(ptr[i]);
	}
      }
    }else{
      st.insert(itr->second);
    }
  }
  if(ans.empty()){
    cout<<"No element has duplicate number of occurrences in this array!"<<endl;
  }else{
    cout<<"Elements which have duplicate number of occurrences in the array: ";
    for(int n : ans){
      cout<<n<<" ";
    }
    putchar('\n');
  }
  return;
}

int main(){

  int num;
  cout<<"Enter the number elements you want to insert in the array: ";
  cin>>num;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"In this problem we want to detect if any element in the array has duplicate number of occurrences:- "<<endl;
  cout<<"Enter the elements in the array:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element - "<<(i + 1)<<": ";
    cin>>ptr[i];
  }
  
  detectDuplicateOccurrence(ptr, num); 
  return 0;
}
