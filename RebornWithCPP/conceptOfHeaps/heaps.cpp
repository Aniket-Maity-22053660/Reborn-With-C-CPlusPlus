#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Heap{
    vector<int> arr;
    int size;
    int capacity;
    void insert(int);
    void swap(vector<int>&, int, int);
    void heapify(vector<int> &arr, int i, int capacity);
    void increaseKey(vector<int>&, int, int);
    int extractMax();
    int deleteHeap(int);
    public:
    Heap(int size){
        arr.assign(size, 0);
        this->size = size;
        this->capacity = 0;
    }
    void insertIntoHeap();
    void deleteAtHeap();
};

int Heap::deleteHeap(int pos){
    increaseKey(arr, pos, INT_MAX);
    int val = extractMax();
    return val;
}

void Heap::deleteAtHeap(){
    int pos;
    cout<<"Enter the index of the element of which you want to delete: ";
    cin>>pos;
    int ans = deleteHeap(pos);
    if(ans != -1){
        cout<<pos<<" deleted successfully!"<<endl;
    }
    return;
}
int Heap::extractMax(){
    if(capacity > 0){
        int max = arr.at(0);
        swap(arr, 0, capacity - 1);
        capacity--;
        heapify(arr, 0, capacity);
        return max;
    }
    return -1;
}

void Heap::swap(vector<int> &arr, int i, int j){
    int temp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j) = temp;
}

void Heap::heapify(vector<int> &arr, int i, int capacity){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max = i;
    if(left < capacity && arr.at(left) > arr.at(max)){
        max = left;
    }
    if(right < capacity && arr.at(right) > arr.at(max)){
        max = right;
    }
    if(i != max){
        swap(arr, i, max);
        heapify(arr, max, capacity);
    }
    return;
}

void Heap::increaseKey(vector<int> &arr, int i, int key){
    arr.at(i) = key;
    while(i > 0 && arr.at((i - 1) / 2) < arr.at(i)){
        swap(arr, i, (i - 1) / 2);
        i = (i - 1)/ 2;
    }
    return;
}

void Heap::insert(int data){
    if(capacity < size){
        capacity++;
        increaseKey(arr, capacity - 1, data);
    }else{
        cout<<"Heap is full!"<<endl;
    }
    return;
}

void Heap::insertIntoHeap(){
    int data;
    cout<<"Enter the data you want enter in the heap: ";
    cin>>data;
    insert(data);
}