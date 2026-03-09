#include <iostream>
#include<queue>

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

class Queue{
    Node* front, *rear;
    void print(Node*);
    public:
    Queue(){
        this->front = NULL;
        this->rear = NULL;
    }
    void enque(int);
    void deque();
    bool empty();
    int getFront();
    int getBack();
    void printQueue();
};

void Queue::print(Node* temp){
    if(temp != NULL){
        cout<<temp->data;
        if(temp->next != NULL){
            cout<<"->";
        }
        print(temp->next);
        return;
    }
    putchar('\n');
    return;
}

void Queue::printQueue(){
    print(rear);
}

bool Queue::empty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

void Queue::enque(int data){
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

void Queue::deque(){
    if(empty()){
        cout<<"Queue underflow!"<<endl;
    }else{
        Node* temp = rear;
        rear = rear->next;
        if(rear == NULL){
            front = rear;
        }
        delete temp;
    }
    return;
}

int Queue::getFront(){
    if(empty()){
        cout<<"Queue underflow!"<<endl;
    }else{
        return front->data;
    }
    return -1;
}

int Queue::getBack(){
    if(empty()){
        cout<<"Queue underflow!"<<endl;
    }else{
        return rear->data;
    }
    return -1;
}



int main() {
    Queue* q = new Queue();
    int num = q->getFront();
    q->enque(34);
    q->enque(41);
    q->enque(93);
    if(num != -1){
      cout<<"Front: "<<num<<endl;
    }
    q->printQueue();
    q->deque();
    q->printQueue();
    return 0;
}
