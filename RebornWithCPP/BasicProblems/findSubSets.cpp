#include<iostream>
#include<vector>
#include<memory>

using namespace std;

void findSubSet(unique_ptr<int []> &ptr, vector<int> res, int num, int i, vector<vector<int>> &ans){
  if(i < num){
    findSubSet(ptr, res, num, i + 1, ans);
    res.push_back(ptr[i]);
    findSubSet(ptr, res, num, i + 1, ans);
    return;
  }
  if(i == num){
    ans.push_back(res);
  }
  return;
}

int main(){
  int num;
  cout<<"Enter the number of elements you want to enter in the set: ";
  cin>>num;
  unique_ptr<int []> ptr = make_unique<int []>(num);
  cout<<"Enter the set elements:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<i + 1<<": ";
    cin>>ptr[i];
  }
  vector<vector<int>> ans;
  vector<int> res;
  findSubSet(ptr, res, num, 0, ans);
  cout<<"Given set: ";
  for(int i = 0 ; i < num ; i++){
    cout<<ptr[i]<<" ";
  }
  putchar('\n');
  cout<<"Subsets: ";
  vector<int>::iterator itr;
  
  cout<<'[';
  for(int i = 0 ; i < ans.size() ; i++){
    cout<<'[';
    for(itr = ans.at(i).begin() ; itr != ans.at(i).end() ; itr++){
      cout<<*itr;
      if(next(itr) != ans.at(i).end()){
	cout<<", ";
      }
    }
    cout<<']';
    if(i != ans.size() - 1){
      cout<<", ";
    }
  }
  cout<<']'<<endl;
  return 0;
}
