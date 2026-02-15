#include<iostream>
#include<vector>

using namespace std;

void printArray(const vector<int> &arr){
  vector<int>::const_iterator itr;

  cout<<"Content of the array: ";
  for(itr = arr.cbegin() ; itr != arr.cend() ; itr++){
    cout<<*itr<<" ";
  }
  putchar('\n');
}
vector<int> merge(const vector<int> &vec1, const vector<int> &vec2){

  int n1 = vec1.size();
  int n2 = vec2.size();
  int i = 0, j = 0, k = 0;
  vector<int> vec(n1 + n2);
  while(i < n1 && j < n2){
    if(vec1.at(i) < vec2.at(j)){
      vec.at(k++) = vec1.at(i++);
    }else{
      vec.at(k++) = vec2.at(j++);
    }
  }
  while(i < n1){
    vec.at(k++) = vec1.at(i++);
  }
  while(j < n2){
    vec.at(k++) = vec2.at(j++);
  }
  return vec;
}

vector<int> mergeSort(const vector<int> &vec, int i, int j){
#include<iostream>
#include<vector>
#define findMin(num1, num2) (num1 > num2 ? num2 : num1)
#define findMax(num1, num2) (num1 > num2 ? num1 : num2)

using namespace std;

void printArray(vector<int> &vec){
  cout<<"Contents of the array: ";
  vector<int>::iterator itr;
  for(itr = vec.begin() ; itr != vec.end() ; itr++){
    cout<<*itr<<" ";
  }
  putchar('\n');
}

vector<int> findMinMax(vector<int> arr, int i, int j, vector<int> vec){
  if(i < j){
    int mid = i + (j - 1) / 2;

    vector<int> vec1 = findMinMax(arr, i, mid, vec);
    vector<int> vec2 = findMinMax(arr, mid+1, j, vec);

    int min = findMin(vec1.at(0), vec2.at(1));
    int max = findMax(vec1.at(1), vec2.at(1));

    vec.at(0) = min;
    vec.at(1) = max;

    return vec;
  }
  return {arr.at(i), arr.at(j)};

}
int main(){

  int num;
  cout<<"Enter the size of the array: ";
  cin>>num;

  vector<int> arr(num, 0);
  cout<<"Enter the elements: "<<endl;

  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element "<<(i)<<": ";
    cin>>arr.at(i);

  }

  printArray(arr);

  vector<int> vec(2);

  vector<int> ans = findMinMax(arr, 0, num - 1, vec);
  cout<<"Max element of the array: "<<ans.at(1)<<endl;
  cout<<"Min element of the array: "<<ans.at(0)<<endl;

  return 0;
}
  if(i < j){

    int mid = i + (j - i) / 2;
    vector<int> vec1 = mergeSort(vec, i, mid);
    vector<int> vec2 = mergeSort(vec, mid + 1, j);
    vector<int> ans = merge(vec1, vec2);
    
    return ans;
  }
  return {vec.at(i)};
}
int main(){

  int num;
  cout<<"Enter the size of the array: ";
  cin>>num;
  
  vector<int> vec(num);
  
  cout<<"Enter the elements of the array:- "<<endl;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element-"<<(i)<<": ";
    cin>>vec.at(i);
  }
  printArray(vec);
  vector<int> arr = mergeSort(vec, 0, num - 1);
  cout<<"Merge Sort:- "<<endl;
  printArray(arr);
  
  
  
  return 0;
}
