#include<iostream>

using namespace std;

class CircularQueue{
  int front, rear;
  int* arr;
  int size;
  //void print();
public:
  CircularQueue(int size){
    front = -1;
    rear = -1;
    this->size = size;
    arr = new int[size];
  }
  void enQueue(int data);
  void deQueue();
  int getFront();
  int getBack();
  bool empty();
  void printQueue();
};

void CircularQueue::printQueue(){
  for(int i = rear ; i <= front ; i++){
    cout<<arr[i];
    if(i != front){
      cout<<"->";
    }
  }
  putchar('\n');
}

bool CircularQueue::empty(){
  if(front == -1 && rear == -1){
    return true;
  }else{
    return false;
  }
}

void CircularQueue::enQueue(int data){
  if(empty()){
    front++;
    rear++;
    arr[(front)] = data;
  }else if((front + 1) % size != rear){
    front = (front + 1) % size;
    arr[front] = data;
  }
  else{
    cout<<"Queue overflow!"<<endl;
  }
  return;
}

void CircularQueue::deQueue(){
  if(empty()){
    cout<<"Queue underflow!"<<endl;
    return;
  }
  arr[rear] = 0;
  if(front == rear){
    front = -1;
    rear = -1;
  }else{
    rear = (rear + 1) % size;
  }
  return;
}

int CircularQueue::getFront(){
  if(empty()){
    cout<<"Queue underflow!"<<endl;
    return -1;
  }
  return arr[(front)];
}

int CircularQueue::getBack(){
  if(empty()){
    cout<<"Queue underflow!"<<endl;
    return -1;
  }
  return arr[(rear)];
}
int main(){
  int size;
  cout<<"Enter the size of the queue: ";
  cin>>size;
  CircularQueue* queue = new CircularQueue(size);
  queue->enQueue(40);
  queue->enQueue(90);
  queue->enQueue(50);
  queue->enQueue(100);
  queue->printQueue();
  return 0;
}
