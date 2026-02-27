#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> res;

void make_matrix(int row, int col){
  cout<<"Enter the elements for the matrix:- "<<endl;
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      cout<<"Enter element["<<i<<"]["<<j<<"]: ";
      cin>>arr.at(i).at(j);
    }
  }
}

void printMatrix(vector<vector<int>> &arr, int row, int col){
  //  cout<<"Given matrix:- "<<endl;
  for(int i = 0 ; i < row ; i++){
    for(int j: arr.at(i)){
      printf("%4d", j);
    }
    putchar('\n');
  }
  putchar('\n');
}

void findTranspose(int row, int col){
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      res.at(j).at(i) = arr.at(i).at(j); 
    }
  }
}

void swap(vector<int> &arr, int i, int j){
  int temp = arr.at(i);
  arr.at(i) = arr.at(j);
  arr.at(j) = temp;
}

void reverse(vector<int> &arr, int i, int j){
  if(i < j){
    swap(arr, i, j);
    reverse(arr, i + 1, j - 1);
  }
}

void rotate(int i){
  if(i < arr.size()){
    reverse(res.at(i), 0, res.at(i).size() - 1);
    rotate(i + 1);
  }
}
int main(){
  int row, col;
  cout<<"Enter the rows for the matrix: ";
  cin>>row;
  cout<<"Enter the columns for the matrix: ";
  cin>>col;
  arr.assign(row, vector<int> (col));
  res.assign(col, vector<int> (row));
  make_matrix(row, col);
  cout<<"Given Matrix:- "<<endl;
  printMatrix(arr, row, col);
  findTranspose(row, col);
  rotate(0);
  cout<<"After rotation:- "<<endl;
  printMatrix(res, row, col);
  return 0;
}
