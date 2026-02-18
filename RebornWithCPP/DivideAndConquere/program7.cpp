#include<iostream>
#include<vector>

using namespace std;

struct knapsack{
  string name;
  double profit;
  double weight;
};

void printSequence(vector<string> vec){
  vector<string>::iterator itr;

  for(itr = vec.begin() ; itr != vec.end() ; itr++){
    cout<<*itr;
    if(next(itr) != vec.end()){
      cout<<"->";
    }
  }
  putchar('\n');
}

void swap(vector<knapsack> &vec, int i, int j){
  struct knapsack knap = vec.at(i);
  vec.at(i) = vec.at(j);
  vec.at(j) = knap;
}

vector<string> fillSack(vector<knapsack> &knapVec, double num, double &profit){
  vector<string> vec(knapVec.size());
  double M = num;
  int k = 0;
  int i = 0;
  while(i < knapVec.size() && M > 0){
    if(M > 0 && knapVec.at(k).weight <= M){
    M = M - knapVec.at(k).weight;
    profit = profit + knapVec.at(k).profit;
    vec.at(k) = "Element-" + to_string(k+1);
    k++;
    i++;
    }else{
      break;
    }
  }
  if(M > 0){
    profit = profit + M * (knapVec.at(k).profit / knapVec.at(k).weight);
    vec.at(k) = "Element-" + to_string(k) + " ("+to_string((int)knapVec.at(k).profit) + " / " + to_string((int)knapVec.at(k).weight) + ")";
  }
  return vec;
  
}

int partition(vector<knapsack> &knapVec, int i){
  int num = knapVec.at(i).profit / knapVec.at(i).weight;
  int k = i;
  for(int j = k+1 ; j < knapVec.size() ; j++){
    if((knapVec.at(j).profit / knapVec.at(j).weight) > num){
      k++;
      swap(knapVec, j, k);
    }
  }
  swap(knapVec, i, k);
  return k;
}

void quickSort(vector<knapsack> &knapVec, int i, int j){
  if(i < j){
    int part = partition(knapVec, i);
    quickSort(knapVec, i, part - 1);
    quickSort(knapVec, part + 1, j);
  }
}

int main(){
  int num;
  cout<<"Enter the total number of elements you want to enter in the bag: ";
  cin>>num;
  struct knapsack knap;

  vector<knapsack> knapVec(num);
  int size;
  cout<<"Enter the size of the bag: ";
  cin>>size;

  cout<<"Enter the details of the elements:- "<<endl;;
  
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the profit of the "<<(i+1)<<"th element: ";
    cin>>knapVec.at(i).profit;
    cout<<"Enter the weight of the "<<(i+1)<<"th element: ";
    cin>>knapVec.at(i).weight;
    knapVec.at(i).name = "Element-"+to_string(i+1);
  }

  quickSort(knapVec, 0, knapVec.size() - 1);
  double profit = 0;
  vector<string> ans = fillSack(knapVec, size, profit);
  cout<<"Sequence of elements to maximize the profit in the sack(bag): ";
  printSequence(ans);
  cout<<"Maximized profit for this sequence: "<<profit<<endl;
  return 0;
}
  
