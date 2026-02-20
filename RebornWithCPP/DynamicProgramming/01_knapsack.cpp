#include<iostream>
#include<vector>
#define max(n1, n2) (n1 > n2 ? n1 : n2)

using namespace std;

int solve_01_knapsack(vector<int> weight, vector<int> profit,vector<vector<int>> &t, int size, int n){
  if(size == 0 ||  n == 0){
    return 0;
  }

  if(t.at(size).at(n - 1) != -1){
    return t.at(size).at(n - 1);
  }

  if(weight.at(n - 1) <= size){
    t.at(size).at(n - 1) = max(profit.at(n - 1) + solve_01_knapsack(weight, profit, t, size - weight.at(n - 1), n - 1), solve_01_knapsack(weight, profit, t, size, n - 1));
  }
  else{
    t.at(size).at(n - 1) = solve_01_knapsack(weight, profit, t, size, n - 1);
  }

  return t.at(size).at(n - 1);
  
}


int main(){
  int num;
  int size;
  cout<<"Enter how many elements you want to enter in the bag(sack): ";
  cin>>num;
  cout<<"Enter the size of the bag(sack): ";
  cin>>size;

  vector<int> weight(num);
  vector<int> profit(num);
  vector<vector<int>> t(size + 1, vector<int> (num + 1, -1));
  cout<<"Enter the weights of the element:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the weight of the element - "<<(i+1)<<": ";
    cin>>weight.at(i);
  }

  cout<<"Enter the profits of the elements:-"<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the profit of the element - "<<(i+1)<<": ";
    cin>>profit.at(i);
  }
  int max_profit = solve_01_knapsack(weight, profit, t, size, weight.size());
  cout<<"Maximum profit after creating the knapsack: "<<max_profit<<endl;
  return 0;
}
