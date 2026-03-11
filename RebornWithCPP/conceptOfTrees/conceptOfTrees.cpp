#include<iostream>
#include<queue>
#include<deque>

using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

class Tree{
  Node* root;
  Node* create();
  void levelTrav(queue<Node*>&);
  void inTrav(Node*);
  void buildFromLevel(queue<Node*>, deque<int>);
public:
  Tree(){
    this->root = NULL;
  }
  void createTree();
  void levelOrderTrav();
  void inOrderTrav();
  void buildFromLevelOrder();
};

void Tree::buildFromLevel(queue<Node*> q, deque<int> arr){
  if(!q.empty()){
    Node* temp = q.front();
    q.pop();
    
    if(!arr.empty()){
      temp->left = new Node(arr.front());
      q.push(temp->left);
      arr.pop_front();
    }else{
      temp->left = NULL;
    }

    if(!arr.empty()){
      temp->right = new Node(arr.front());
      q.push(temp->right);
      arr.pop_front();
    }else{
      temp->right = NULL;
    }

    buildFromLevel(q, arr);
  }
  return;
}

void Tree::buildFromLevelOrder(){
  int num = 0;
  cout<<"Enter the total number of elements for level order traversal: ";
  cin>>num;
  if(num != 0){
  deque<int> arr(num);
  for(int i = 0 ; i < num ; i++){
    cout<<"Enter element - "<<(i + 1)<<": ";
    cin>>arr.at(i);
  }
  queue<Node*> q;
  Node* root = new Node(arr.front());
  q.push(root);
  arr.pop_front();
  buildFromLevel(q, arr);
  cout<<"Given level-order sequence: ";
  deque<int>::iterator itr;
  for(itr = arr.begin() ; itr != arr.end() ; itr++){
    cout<<*itr<<" "; 
  }
  putchar('\n');
  cout<<"Built tree from level-order traversal!"<<endl;
  //builtFromLevel(q, arr);
  inTrav(root);
  putchar('\n');
  }else{
    cout<<"Tree is empty!"<<endl;
  }
  return;
}

void Tree::inTrav(Node* root){
  if(root != NULL){
    inTrav(root->left);
    cout<<root->data<<" ";
    inTrav(root->right);
  }
  return;
}

void Tree::inOrderTrav(){
  cout<<"In-order tree traversal:- "<<endl;
  inTrav(root);
  putchar('\n');
}

void Tree::levelTrav(queue<Node*> &q){
  if(!q.empty()){
    Node* temp = q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left != NULL){
      q.push(temp->left);
    }
    if(temp->right != NULL){
      q.push(temp->right);
    }
    levelTrav(q);
    return;
  }
  putchar('\n');
  return;
}

void Tree::levelOrderTrav(){
  queue<Node*> q;
  if(root != NULL){
    cout<<"Level order traversal:- "<<endl;
    q.push(root);
    levelTrav(q);
  }else{
    cout<<"Tree is empty!"<<endl;
  }
  return;
}

Node* Tree::create(){
  int data;
  cout<<"Enter the data: ";
  cin>>data;
  if(data == -1){
    return NULL;
  }
  Node* node = new Node(data);

  cout<<"Enter the left child for "<<data<<":- "<<endl;
  node->left = create();

  cout<<"Enter the right child for "<<data<<":- "<<endl;
  node->right = create();

  return node;
}

void Tree::createTree(){
  root = create();
}

int main(){
  Tree* tree = new Tree();
  tree->createTree();
  tree->levelOrderTrav();
  tree->inOrderTrav();
  tree->buildFromLevelOrder();
  return 0;
}
