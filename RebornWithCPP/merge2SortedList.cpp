#include<iostream>

using namespace std;

class Node{
public:
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
  int data;
  Node* next;
};

void insertAtTail(Node* head, int data){
  if(head->next != NULL){
    insertAtTail(head->next, data);
    return;
  }
  Node* node = new Node(data);
  head->next = node;
  return;
}

void insert(Node** head, int data){
  if(*head != NULL){
    insertAtTail(*head, data);
  }else{
    Node* node = new Node(data);
    *head = node;
  }

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

void merge(Node** head1, Node** head2, Node** head3){
  if(*head1 != NULL && *head2 != NULL){
    if((*head1)->data < (*head2)->data){
      insert(head3, (*head1)->data);
      *head1 = (*head1)->next;
    }else{
      insert(head3, (*head2)->data);
      *head2 = (*head2)->next;
    }
    merge(head1, head2, head3);
    return;
  }
  return;
}

void mergeList1(Node* head1, Node** head3){
  if(head1 != NULL){
    insert(head3, head1->data);
    mergeList1(head1->next, head3);
    return;
  }
  return;
}

void mergeList2(Node* head2, Node** head3){
  if(head2 != NULL){
    insert(head3, head2->data);
    mergeList2(head2->next, head3);
    return;
  }
  return;
}

Node* merge2List(Node* head1, Node* head2){
  Node* head3 = NULL;
  merge(&head1, &head2, &head3);
  mergeList1(head1, &head3);
  mergeList2(head2, &head3);
  return head3;
}

int main(){
  Node* head1 = NULL, *head2 = NULL, *head3 = NULL;
  int num, element;
  cout<<"Enter total number of nodes in the LinkedList - 1: ";
  cin>>num;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>element;
    insert(&head1, element);
  }
  cout<<"List - 1: ";
  printNodes(head1);
  cout<<"Enter total number of nodes in the LinkedList - 2: ";
  cin>>num;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>element;
    insert(&head2, element);
  }
  cout<<"List - 2: ";
  printNodes(head2);
  head3 = merge2List(head1, head2);
  cout<<"After merging two lists: ";
  printNodes(head3);
  return 0;
}
