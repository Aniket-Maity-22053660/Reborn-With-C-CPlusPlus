#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void swap(vector<int> &arr, int i, int j){
  int temp = arr.at(i);
  arr.at(i) = arr.at(j);
  arr.at(j) = temp;
}

void printArray(const vector<int> &arr){
  vector<int>::const_iterator itr;
  for(itr = arr.cbegin() ; itr != arr.cend() ; itr++){
    cout<<*itr<<" ";
  }
  putchar('\n');
}


void buildMaxHeap(vector<int> &arr, int i){

  int l = 2*i + 1;
  int r = 2*i + 2;
  int largest;

  if(l < arr.size() && arr.at(l) > arr.at(i)){
    largest = l;
  }else{
    largest = i;
  }
  if(r < arr.size() && arr.at(r) > arr.at(largest)){
    largest = r;
  }
  if(largest != i){
    swap(arr, largest, i);
    buildMaxHeap(arr, largest);
  }
}

int extractMaxHeapElement(vector<int> &arr){
  int max = arr.at(0);
  int num = arr.back();
  arr.at(0) = num;
  arr.pop_back();
  buildMaxHeap(arr, 0);
  return max;
}

int findParent(int i){
  return (i - 1) / 2;
}

void increaseKey(vector<int> &arr, int back, int key){
  if(key < arr.at(back)){
    cout<<"Heap underflow!"<<endl;
  }
  int parent = (back - 1) / 2;
  int i = back;
  arr.at(back) = key;

  while(i > 0 && arr.at((i / 2) - 1) < key){
    swap(arr, i, (i / 2) - 1);
    i = (i / 2) - 1;
  }
}

void insertKey(vector<int> &arr, int key){
  arr.push_back(INT_MIN);
  increaseKey(arr, arr.size() - 1, key);
}

vector<int> heapSort(vector<int> &arr){

  vector<int> sorted(arr.size());
  int k = arr.size() - 1;
  for(int i = (arr.size() / 2) - 1 ; i >= 0 ; i--){
    buildMaxHeap(arr, i);
  }

  for(int i = arr.size() - 1 ; i >= 0 ; i--){
    swap(arr, 0, i);
    sorted.at(k--) = arr.at(arr.size() - 1);
    arr.pop_back();

    for(int j = (arr.size() / 2) - 1 ; j >= 0 ; j--){
      buildMaxHeap(arr, j);
    }
  }
  return sorted;
}

int main(){
  int num;
  cout<<"Enter the size of the array: ";
  cin>>num;
  cout<<"Enter the contents of the array:- "<<endl;
  vector<int> arr(num);
  for(int i = 0 ; i < num ; i++){
    cout<<"enter the element-"<<i<<":";
    cin>>arr.at(i);
  }
  cout<<"Contents of the array: ";
  printArray(arr);
  for(int i = (num / 2) - 1 ; i >= 0 ; i--){
    buildMaxHeap(arr, i);
  }
  cout<<"After constructing the max heap: ";
  printArray(arr);
  cout<<"Max element of the heap: "<<extractMaxHeapElement(arr)<<endl;
  cout<<"Max Heap after extracting the max element: ";
  printArray(arr);
  int key;
  cout<<"Enter the key you want to insert: ";
  cin>>key;
  insertKey(arr, key);
  cout<<"After insertion Max Heap: ";
  printArray(arr);
  cout<<"Enter the size of the array for performing Heap Sort: ";
  cin>>num;
  cout<<"Enter the contents of the array:- "<<endl;
  vector<int> arr1(num);
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element-"<<i<<": ";
    cin>>arr1.at(i);
  }
  cout<<"Content  of the array before Heap Sort: ";
  printArray(arr1);
  arr1 = heapSort(arr1);
  cout<<"Content  of the array after Heap Sort: ";
  printArray(arr1);
  return 0;
}


