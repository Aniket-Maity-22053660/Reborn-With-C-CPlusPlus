#include<iostream>

using namespace std;

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  int k = 1;

  for(int i = 0 ; i < n ; i++){
    for(int j = i ; j >= 0 ; j--){
      printf("%3d", k++);
    }
    putchar('\n');
  }
  return 0;
}
