#include<iostream>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};

struct Node* insertAtHead(struct Node* head, int element){
  struct Node* node = new Node;
  node->next = head;
  head = node;
  head->data = element;
  return head;
}

void printNodes(struct Node* head){
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

struct Node* reverse(struct Node* temp1, struct Node** temp2, struct Node* temp3, int k){
  if(*temp2 != NULL && k > 0){
    (*temp2)->next = temp1;
    temp1 = *temp2;
    *temp2 = temp3;
    if(temp3 != NULL){
      temp3 = temp3->next;
    }
    return reverse(temp1, temp2, temp3, k - 1);
  }
  return temp1;
}

struct Node* reverseInK(struct Node* head, int k){
  if(head != NULL){
     struct Node* temp1, *temp2, *temp3;
     temp1 = NULL;
     temp2 = head;
     temp3 = temp2->next;
     
     struct Node* temp = reverse(temp1, &temp2, temp3, k);
     head->next = reverseInK(temp2, k);
     return temp;
  }
  return NULL;
}

int main(){
  int num, element, k;
  cout<<"Enter the number of nodes in the LinkedList: ";
  cin>>num;
  cout<<"Enter the size of the K group: ";
  cin>>k;
  struct Node* head = NULL;
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter the element - "<<(i + 1)<<": ";
    cin>>element;
    head = insertAtHead(head, element);
  }
  cout<<"Given list: ";
  printNodes(head);
  head = reverseInK(head, k);
  cout<<"After reversed in "<<k<<" groups: ";
  printNodes(head);
  
  return 0;
}
