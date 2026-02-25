#include<iostream>
#include<memory>

using namespace std;

void swap(string &temp, int i, int j){
  char temp1 = temp.at(i);
  temp.at(i) = temp.at(j);
  temp.at(j) = temp1;
}

void reverse(string &temp, int i, int j){
  if(i < j){
    swap(temp, i, j);
    reverse(temp, i + 1, j - 1);
  }
}

void reverseWords(string &name, int i, int num, string &ans, string temp){
  if(i < num){
    if(name[i] == ' '){
      reverse(temp, 0, temp.length() - 1);
      ans.append(temp);
      ans.push_back(' ');  
      temp = "";
    }else{
      temp.push_back(name[i]);
    }
    reverseWords(name, i + 1, num, ans, temp);
  }
  if(i == num - 1){
  reverse(temp, 0, temp.length() - 1);
  ans.append(temp);
  temp = "";
  }
}

int main(){

  string name, ans = "", temp = "";
  cout<<"Enter your string: ";
  getline(cin, name);
  reverseWords(name, 0, name.length(), ans, temp);
  cout<<"After reversal of the words: ";
  cout<<ans<<endl;
  return 0;
}
