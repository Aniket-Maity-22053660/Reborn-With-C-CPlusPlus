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
    Node::count++;
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

Node* deleteAtHead(Node* head){
  if(head != NULL){
    Node* temp = head;
    head = head->next;
    delete temp;
    Node::count--;
    return head;
  }
  return head;
}

void deleteAtTail(Node* head){
  if(head == NULL){
    return;
  }
  if(head->next->next != NULL){
    deleteAtTail(head->next);
  }else{
    Node* temp = head->next;
    head->next = NULL;
    delete temp;
    Node::count--;
    return;
  }
  return;
}

void delAtPos(Node* head, int position){
  if(position != 2){
    delAtPos(head->next, position - 1);
  }else{
    Node* temp = head->next->next;
    Node* temp1 = head->next;
    head->next = temp;
    temp->prev = head;
    Node::count--;
    delete temp1;
  }
  return;
}

void deleteAtPos(Node** head, int position){
  if(position == 1){
    *head = deleteAtHead(*head);
    return;
  }
  if(position == Node::count){
    deleteAtTail(*head);
    return;
  }
  delAtPos(*head, position);
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
  insertAtPosition(&head, 2, 60);
  printNodes(head);
  head = deleteAtHead(head);
  printNodes(head);
  deleteAtTail(head);
  printNodes(head);
  deleteAtPos(&head, 3);
  printNodes(head);
  return 0;
}
