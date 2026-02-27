#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &arr, int j){
  if(j < arr.size()){
    cout<<arr[j]<<" ";
    print(arr, j + 1);
  }
}

void printMatrix(vector<vector<int>> &arr, int i){
  if(i < arr.size()){
    print(arr.at(i), 0);
    cout<<'\n';
    printMatrix(arr, i + 1);
  }
}

void calcRowSum(vector<int> &arr, int i, int &sum1){
  if(i < arr.size()){
    sum1 = sum1 + arr.at(i);
    calcRowSum(arr, i + 1, sum1);
  }
}

void rowSum(vector<vector<int>> &arr, int i, int &sum){
  if(i < arr.size()){
    int sum1 = 0;
    calcRowSum(arr.at(i), 0, sum1);
    sum += sum1;
    cout<<i+1<<"th row sum: "<<sum1<<endl;
    rowSum(arr, i + 1, sum);
  }
}

void calcColSum(const vector<vector<int>> &arr, int i, int j, int &sum){
  if(i < arr.size()){
    sum += arr[i][j];
    calcColSum(arr, i + 1, j, sum);
  }
}

void colSum(const vector<vector<int>> &arr, int i){
  if(i < arr.at(0).size()){
    int sum = 0;
    calcColSum(arr, 0, i, sum);
    cout<<i+1<<"th column sum: "<<sum<<endl;
    colSum(arr, i + 1);
  }
}

int main(){
  int row, col;
  cout<<"Enter the row of the matrix: ";
  cin>>row;
  cout<<"Enter the column of the matrix: ";
  cin>>col;
  vector<vector<int>> arr(row, vector<int>(col));
  cout<<"Enter the elements of the matrix:- "<<endl;
  for(int i = 0 ; i < row; i++){
    for(int j = 0 ; j < col ; j++){
      cout<<"Enter element["<<i<<"]["<<j<<"]: ";
      cin>>arr.at(i).at(j);
    }
  }
  cout<<"Given matrix:- "<<endl;
  printMatrix(arr, 0);
  cout<<"Printing row-wise sum:- "<<endl;
  int sum = 0;
  rowSum(arr, 0, sum);
  cout<<"Printing column-wise sum:- "<<endl;
  colSum(arr, 0);
  return 0;
}
