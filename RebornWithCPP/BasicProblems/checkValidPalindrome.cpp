#include<iostream>
#include<memory>

using namespace std;

bool checkPalindrome(string temp, int i, int j){
  if(i < j){
    if(temp[i] != temp[j]){
      return false;
    }
    return checkPalindrome(temp, i + 1, j - 1);
  }
  return true;
}

int main(){
  string name;
  cout<<"Enter the string: ";
  cin>>name;
  string temp = "";

  for(int i = 0 ; i < name.size() ; i++){
    if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' || name[i] <= 'Z') || (name[i] >= 0 && name[i] <= 9)){
      temp.push_back(name[i]);
    }
  }

  for(int i = 0 ; i < temp.length() ; i++){
    if(temp[i] >= 65 && temp[i] <= 90){
      temp[i] = temp[i] + 32;
    }
  }

  bool ans = checkPalindrome(temp, 0, temp.length() - 1);
  if(ans){
    cout<<"Given string is a palindrome!"<<endl;
  }else{
    cout<<"Given string is not a palindrome!"<<endl;
  }
  return 0;
}
