#include<iostream>

using namespace std;

int findComplement(int num){
  int m = num;
  int mask = 0;
  if(num == 0){
    return 1;
  }
  while(m != 0){
    mask = (mask << 1) | 1;
    m = m >> 1;
  }
  return ~num & mask;
}
int main(){
  int num;
  cout<<"Enter the decimal number: ";
  cin>>num;
  int ans = findComplement(num);
  cout<<"Base 10 complement of "<<num<<" is "<<ans<<endl;
  return 0;
}
