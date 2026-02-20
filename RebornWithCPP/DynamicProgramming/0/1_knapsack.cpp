#include<iostream>
#include<map>
#include<vector>
#define max(n1, n2) (n1 > n2 ? n1 : n2)
using namespace std;


int solve_01_knapsack(vector<int> weight, vector<int> profit, int size, int n){
  if(size == 0 || weight.size() == 0){
    return 0;
  }

  if(weight.at(n - 1) <= size){
    return max(profit.at(n - 1) + solve_01_knapsack(weight, profit, size - weight.at(n - 1), n - 1), solve_01_knapsack(weight, profit, size, n - 1));
  }
  else{
    return solve_01_knapack(weight, profit, size, n - 1);
  }
}

int main(){
  int num;
  cout<<"Enter the number of elements you want to insert in the bag(sack): ";
  cin>>num;
  vector<int> profit(num);
  vector<int> weight(num);
  cout<<"Enter the profits:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the profit of the "<<i+1<<"th element: ";
    cin>>profit.at(i);
  }
  cout<<"Enter the weights:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the weight of the "<<(i+1)<<"th element: ";
    cin>>weight.at(i);
  }
  int size;
  cout<<"Enter the size of your bag(sack): ";
  cin>>size;
  int max_profit = solve_01_knapsack(weight, profit, size, weight.size());
  
  return 0;
}
