#include<iostream>

using namespace std;

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;
  for(int i = 0 ; i < n ; i++){
    for(int j = i ; j >= 0 ; j--){
      cout<<'*';
    }
    putchar('\n');
  }
  return 0;
}
