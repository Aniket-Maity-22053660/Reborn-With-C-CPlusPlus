#include<iostream>
#include<string>

using namespace std;

void removeAdjacent(string &name, int i){
  if(name.length() > 1 && i < name.length() - 1){
    if(name.at(i) == name.at(i + 1)){
      name.erase(i, 2);
      i = 0;
    }else{
      i = i + 1;
    }
    removeAdjacent(name, i);
  }
}

int main(){
  string name;
  cout<<"Enter your string: ";
  getline(cin, name);
  cout<<"Given string: "<<name<<endl;
  removeAdjacent(name, 0);
  cout<<"After removing all the adjacent duplicates: "<<name<<endl;
  
  return 0;
}
