#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int main(){
  int num;
  cout<<"Enter the number: ";
  cin>>num;
  int cnt = 0, i = 0;
  double res = 0;
  while(num != 0){
    int rem = num % 10;
    if(res > INT_MAX / 10 || res < INT_MIN / 10){
      return 0;
    }
    res = res*10 + rem;
    num = num / 10;
  }
  cout<<"After reversal: "<<res<<endl;
  return 0;
}
