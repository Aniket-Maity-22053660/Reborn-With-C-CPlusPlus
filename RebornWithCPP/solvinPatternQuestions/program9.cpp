#include<iostream>

using namespace std;

int main(){
  int n;
  cout<<"Enter the value of n: ";
  cin>>n;

  char ch = 'A';

  for(int i = 0 ; i < n ; i++){
    char ch1 = ch++;
    for(int j = i ; j >= 0 ; j--){
      printf("%3c", ch1++);
    }
    putchar('\n');
  }
  return 0;
}
