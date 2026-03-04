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
  }
  return;
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
  return 0;
}
