#include<iostream>
#include<array>
#include<deque>

using namespace std;

namespace mySpace1{
  deque<int> dq;
  }

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
  cout<<"Maximum number of elements that can be held by the array container: "<<arr.max_size()<<endl;
  cout<<"Total number of elements currently present in this array: "<<arr.size()<<endl;
  deque<int> dq(25, 77);
  cout<<"Deque elements: ";
  for(int i = 0 ; i < dq.size() ; i++){
    cout<<dq[i]<<" ";
  }
  putchar('\n');
  array<int, 100> arr2;
  for(int i = 0 ; i < 100 ; i++){
    arr2[i] = i;
  }
  deque<int> dq1(arr2.begin(), arr2.end());
  for(int i = 0 ; i < dq1.size() ; i++){
    cout<<dq1[i]<<" ";
  }
  putchar('\n');
  string name2 = "King star Khan";
  deque<char> myName(name2.begin(), name2.end());
  deque<char>::iterator itr1 = myName.begin();
  while(itr1 != myName.end()){
    cout<<*itr1<<" ";
    itr1++;
  }
  putchar('\n');
  
  mySpace1::dq.push_back(90);
  mySpace1::dq.push_front(100);
  mySpace1::dq.push_back(87);
  mySpace1::dq.push_back(99);
  mySpace1::dq.push_front(999);

  cout<<"dq size: "<<mySpace1::dq.size()<<endl;  

  int size = mySpace1::dq.size();
  for(int i = 0 ; !mySpace1::dq.empty() ; i++){
    mySpace1::dq.pop_front();
  }
  cout<<"dq size: "<<mySpace1::dq.size()<<endl;  
  
  for(int i = 0 ; i < mySpace1::dq.size() ; i++){
    cout<<mySpace1::dq.at(i)<<" ";
  }
  putchar('\n');
  return 0;
}
