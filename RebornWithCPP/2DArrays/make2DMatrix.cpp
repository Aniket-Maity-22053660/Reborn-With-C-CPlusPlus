#include<vector>
#include<iostream>

using namespace std;

vector<vector<int>> arr;

void printMatrix(){
  cout<<"Given matrix: ";
  for(int i = 0 ; i < arr.size() ; i++){
    for(int j: arr.at(i)){
      cout<<j<<" ";
    }
  }
  cout<<'\n';
}

void makeMatrix(int row, int col){
cout<<"Enter the number of rows: ";
cin>>row;
cout<<"Enter the number of cols: ";
cin>>col;

arr.assign(row, vector<int> (col));
cout<<"Enter the elements for the matrix:- "<<endl;
for(int i = 0 ; i < row ; i++){
  for(int j = 0 ; j < col ; j++){
    cout<<"Enter element["<<i<<"]["<<j<<"]: ";
    cin>>arr[i][j];
  }
 }
}

