#include<iostream>

using namespace std;

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  for(int i = 0 ; i < n ; i++){
    int k = i+1;
    for(int j = i ; j >= 0 ; j--){
      printf("%3d", k++);
    }
    putchar('\n');
  }
  return 0;
}
