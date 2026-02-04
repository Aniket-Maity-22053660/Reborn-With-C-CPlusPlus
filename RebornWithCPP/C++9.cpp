#include<iostream>
#include<array>

using namespace std;

int main(){
  array<int, 10> arr = {19, 23, 45 ,21, 54, 90};
  try{
    cout<<"Array elements: ";
    for(int i = 0 ; i < 10 ; i++){
      cout<<arr.at(i)<<" ";
    }
  }catch(const char* msg){
    cout<<msg<<endl;
  }
  putchar('\n');
  arr.back() = 500;
  cout<<"Back of the Array: "<<arr.back()<<endl;
  array<int, 10>::iterator itr = arr.begin();
  while(itr != arr.end()){
    cout<<*itr<<" ";
    itr++;
  }
  putchar('\n');
  int* ptr = arr.data();
  for(int i = 0 ; i < 10 ; i++){
    cout<<*ptr<<" ";
    ptr++;
  }
  putchar('\n');
  cout<<"Whether the array is empty? "<<arr.empty()<<endl;;
  array<int, 5> arr1;
  cout<<"Enter the 5 elements for the array:- "<<endl;
  for(int i = 0 ; i < 5 ; i++){
    cout<<"Enter element "<<(i)<<": ";
    cin>>arr1.at(i);
  }
  cout<<"Array elements: ";
  itr = arr1.begin();
  while(itr != arr1.end()){
    cout<<*itr<<" ";
    itr++;
  }
  putchar('\n');
  arr1.fill(999);
  itr = arr1.begin();
  while(itr != arr1.end()){
    cout<<*itr<<" ";
    itr++;
  }
  putchar('\n');
  
  return 0;
}
