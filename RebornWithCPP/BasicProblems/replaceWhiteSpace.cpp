#include<iostream>
#include<string>

using namespace std;

void replaceWhiteSpaces(string &name, int i){
  if(i < name.length()){
    if(name.at(i) == ' '){
      //name.replace(i, 1, "@40", 0, 2);
      name.insert(i, "@40");
      name.erase(i + 3, 1);
      replaceWhiteSpaces(name, i + 3);
    }else{
    replaceWhiteSpaces(name, i + 1);
    }
    }
}

int main(){
  string name;
  cout<<"Enter your string: ";
  getline(cin, name);
  cout<<"Replace all the whitespace with this special string @40:- "<<endl;
  replaceWhiteSpaces(name, 0);
  cout<<"Modified string: "<<name<<endl;
  return 0;
}
