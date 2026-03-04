#include<iostream>

using namespace std;

class Node{

public:
  Node(int data){
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
  int data;
  Node* prev;
  Node* next;
  static int count;
};

Node* insertAtHead(Node* head, int data){
  Node* temp = new Node(data);
  if(head != NULL){
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  else{
    head = temp;
  }
  Node::count++;
  return head;
}

void insertAtTail(Node* head, int data){
  if(head == NULL){
    return;
  }
  if(head->next != NULL){
    insertAtTail(head->next, data);
  }else{
    Node* node = new Node(data);
    head->next = node;
    node->prev = head;
    Node::count++;
  }
  return;
}

void insertAtPos(Node* head, int position, int data){
  if(position != 2){
    insertAtPos(head->next, position - 1, data);
  }else{
    Node* node = new Node(data);
    Node* temp = head->next;
    temp->prev = node;
    head->next = node;
    node->prev = head;
    node->next = temp;
    return;
  }
  return;
}

void insertAtPosition(Node** head, int position, int data){
  if(position == 1){
    *head = insertAtHead(*head, data);
    return;
  }
  if(position > Node::count){
    insertAtTail(*head, data);
    return;
  }
  insertAtPos(*head, position, data);
}

void printNodes(Node* head){
  if(head != NULL){
    cout<<head->data;
    if(head->next != NULL){
      cout<<"->";
    }
    printNodes(head->next);
    return;
  }
  putchar('\n');
  return;
}



int Node::count = 0;

int main(){

  Node* head = NULL;
  head = insertAtHead(head, 10);
  head = insertAtHead(head, 20);
  head = insertAtHead(head, 30);
  printNodes(head);
  insertAtTail(head, 90);
  printNodes(head);
  insertAtPosition(&head, 4, 50);
  printNodes(head);
  insertAtPosition(&head, 1, 100);
  printNodes(head);
  return 0;
}
