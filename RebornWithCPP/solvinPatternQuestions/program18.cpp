#include<iostream>

using namespace std;

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;
  putchar('\n');
  for(int i = 0 ; i < n ; i++){
    cout<<" ";
  }
  cout<<'*'<<endl;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n - (i+1) ; j++){
      cout<<" ";
    }
    for(int k = i ; k >= 0 ; k--){
      printf("%c", '*');
    }
    for(int k = i ; k >= 0 ; k--){
      printf("%c", '*');
    }
    putchar('\n');
  }
  for(int i = 0 ; i < n ; i++){
    for(int j = i ; j > 0 ; j--){
      cout<<" ";
    }
    for(int k = 0 ; k < n - i ; k++){
      cout<<'*';
    }
    for(int k = 0 ; k < n - i ; k++){
      cout<<'*';
    }
    putchar('\n');
  }
  //putchar('\n');
  for(int i = 0 ; i < n ; i++){
    cout<<" ";
  }
  cout<<'*';
  putchar('\n');
  return 0;
}
