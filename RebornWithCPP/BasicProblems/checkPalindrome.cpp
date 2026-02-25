#include<iostream>
#include<cstring>

using namespace std;

void findLength(char *name, int i, int &num){
  if(name[i] != '\0'){
    num++;
    findLength(name, i + 1 ,num);
  }
}

bool checkPalindrome(char* name, int i, int j){
  if(i < j){
    if(name[i] != name[j]){
      return false;
    }
    return checkPalindrome(name, i + 1, j - 1);
  }
  return true;
}

int main(){
  char name[100];
  cout<<"Enter your string: ";
  cin>>name;
  int num = 0;
  findLength(name, 0, num);
  bool ans = checkPalindrome(name, 0 , num - 1);
  if(ans){
    cout<<name<<" is a palindrome!"<<endl;
  }else{
    cout<<name<<" is not a palindrome!"<<endl;
  }
  return 0;
}
