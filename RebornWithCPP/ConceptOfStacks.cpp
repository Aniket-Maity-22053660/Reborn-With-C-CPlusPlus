#include<iostream>

using namespace std;

class Stack{
  Stack *head, *tail, *next;
  int data;
  bool insertAtTail(int data);
  Stack* deleteAtTail(Stack* tail);
public:
  Stack(){
    this->head = NULL;
    this->tail = NULL;
    this->next = NULL;
  }
  bool push(int data);
  bool pop();
  int top();

};

bool Stack::push(int data){
  return insertAtTail(data);
}

bool Stack::pop(){
  tail = deleteAtTail(head);
  if(tail != NULL){
    return true;
  }
  return false;
}

int Stack::top(){
  if(tail != NULL){
    return tail->data;
  }
  cout<<"Stack is empty!"<<endl;
  return 0;
}

bool Stack::insertAtTail(int data){
  Stack* node = new Stack();
  if(node == NULL){
    return false;
  }
  node->data = data;
  if(head == NULL && tail == NULL){
    head = node;
    tail = node;
  }else{
    tail->next = node;
    tail = node;
  }
  return true;
}

Stack* Stack::deleteAtTail(Stack* tail){
  if(tail == NULL){
    return tail;
  }
  if(tail->next->next != NULL){
    return deleteAtTail(tail->next);
  }
  Stack* temp = tail->next;
  delete temp;
  tail->next = NULL;
  return tail;
}

int main(){
  Stack* st = new Stack();
  if(st->push(34)){
    cout<<"Element pushed to the stack successfully!"<<endl;
  }else{
    cout<<"Failed to push into the stack!"<<endl;
  }
  cout<<"Stack top: "<<st->top()<<endl;
  if(st->push(55)){
    cout<<"Element pushed to the stack successfully!"<<endl;
  }else{
    cout<<"Failed to push into the stack!"<<endl;
  }
  cout<<"Stack top: "<<st->top()<<endl;
  if(st->pop()){
    cout<<"Element was popped from the stack successfully!"<<endl;
  }else{
    cout<<"Stack underflow!"<<endl;
  }
  cout<<"Stack top: "<<st->top()<<endl;
  return 0;
}
