#include<iostream>
#include<queue>
#include<deque>
#include "test.h"
#define max(a, b)( a > b ? a : b)

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
  int height(Node*);
  int diameter(Node*);
  bool isBalanced(Node*);
  bool checkIdentical(Node*, Node*);
  bool sumTree(Node* root, int&);
public:
  Tree(){
    this->root = NULL;
  }
  void createTree();
  void levelOrderTrav();
  void inOrderTrav();
  void buildFromLevelOrder();
  void findHeight();
  void findDiameter();
  void checkBalanced();
  void checkTwoTreesIdentical();
  void checkSumTree();
};

bool Tree::sumTree(Node* root, int &sum){
  if(root != NULL){
    if(root->left == NULL && root->right == NULL){
      sum = root->data;
      return true;
    }
    int lSum = 0, rSum = 0;
    bool left = sumTree(root->left, lSum);
    if(left){
      if(sumTree(root->right, rSum) && root->data == (rSum + lSum)){
        return true;
      }
    }
    return false;
  }
  return true;
}

void Tree::checkSumTree(){
  int sum = 0;
  bool ans = sumTree(root, sum);
  if(ans){
    cout<<"Given tree is a Sum Tree!"<<endl;
  }else{
    cout<<"Given tree is not a Sum Tree!"<<endl;
  }
  return;
}

bool Tree::checkIdentical(Node* root1, Node* root2){
  if(root1 != NULL && root2 != NULL){
    if(root1->data == root2->data){
      bool left = checkIdentical(root1->left, root2->left);
      if(left){
        if(checkIdentical(root1->right, root2->right)){
          return true;
        }
      }
    }
    return false;
  }
  if(root1 == NULL && root2 == NULL){
    return true;
  }
  return false;
}

void Tree::checkTwoTreesIdentical(){
  /*bool ans = checkIdentical(root1,  root2);
  if(ans){
    cout<<"Given two trees are identical!"<<endl;
  }else{
    cout<<"Two trees are not identical!"<<endl;
  }
  return;
  */
}

bool Tree::isBalanced(Node* root){
  if(root == NULL){
    bool left = isBalanced(root->left);
    bool right = false;
    if(left){
      right = isBalanced(root->right);
    }
    if(left && right){
      return abs(height(root->left) - height(root->right)) <= 1 ? true : false;
    }else{
      return false;
    }
  }
  return true;
}

void Tree::checkBalanced(){
  bool ans = isBalanced(root);
}

int Tree::diameter(Node* root){
  if(root != NULL){
    int left = diameter(root->left);
    int right = diameter(root->right);
    int Height = 2 + height(root->left) + height(root->right);
    return max(max(left, right), Height);
  }
  return 0;
}

void Tree::findDiameter(){
  int ans = diameter(root);
  if(ans != 0){
    cout<<"Diameter of the tree: "<<ans<<endl;
  }else{
    cout<<"Tree is empty!"<<endl;
  }
  return;
}

int Tree::height(Node* root){
  if(root != NULL){
    return 1 + max(height(root->left), height(root->right));
  }
  return -1;
}

void Tree::findHeight(){
  int ans = height(root);
  if(ans != -1){
    cout<<"Height of the binary tree: "<<ans<<endl;
  }else{
    cout<<"Tree is empty!"<<endl;
  }
  return;
}

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
  //tree->levelOrderTrav();
  tree->inOrderTrav();
  //tree->buildFromLevelOrder();
  tree->findHeight();
  tree->findDiameter();
  tree->checkSumTree();
  return 0;
}
