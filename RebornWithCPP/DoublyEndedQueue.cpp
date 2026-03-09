#include<iostream>

using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class DoublyEndedQueue{
  Node *front, *rear;
public:
  DoublyEndedQueue(){
    this->front = NULL;
    this->rear = NULL;
  }
  bool empty();
  void push_front(int);
  void push_back(int);
  void pop_back();
  void pop_front();
  int getFront();
  int getBack();
};

bool DoublyEndedQueue::empty(){
  if(front == NULL && rear == NULL){
    return true;
  }else{
    return false;
  }
}

void DoublyEndedQueue::push_front(int data){
  Node* node = new Node(data);
  if(empty()){
    front = node;
    rear = node;
  }else{
    front->next = node;
    front = front->next;
  }
  return;
}

void DoublyEndedQueue::push_back(int data){
  Node* node = new Node(data);
  if(empty()){
    front = node;
    rear = node;
  }else{
    node->next = rear;
    rear = node;
  }
  return;
}

Node* delAtEnd(Node* temp){
  if(temp->next->next != NULL){
    return delAtEnd(temp->next);
  }
  Node* temp1 = temp->next;
  temp->next = NULL;
  delete temp1;
  return temp;
}

void DoublyEndedQueue::pop_back(){
  if(empty()){
    cout<<"Queue underflow!"<<endl;
    return;
  }
  if(front == rear){
    Node* temp = front;
    front = NULL;
    rear = NULL;
    delete temp;
    return;
  }
  front = delAtEnd(rear);
}

void DoublyEndedQueue::pop_front(){
  if(empty()){
    cout<<"Queue underflow!"<<endl;
    return;
  }
  Node* temp = rear;
  if(front == rear){
    front = NULL;
    rear = NULL;
    delete temp;
  }else{
    rear = rear->next;
    delete temp;
  }
  return;
}

int DoublyEndedQueue::getFront(){
  if(empty()){
    cout<<"Queue is empty!"<<endl;
  }else{
    return front->data;
  }
  return -1;
}

int DoublyEndedQueue::getBack(){
  if(empty()){
    cout<<"Queue is empty!"<<endl;
  }else{
    return rear->data;
  }
  return -1;
}

int main(){

  return 0;
}
