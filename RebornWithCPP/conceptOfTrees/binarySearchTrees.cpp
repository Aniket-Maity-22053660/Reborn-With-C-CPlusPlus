#include<iostream>

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

class BST{
    Node* root;
    Node* insert(Node* root, int);
    void inTrav(Node*);
    public:
    BST(){
        this->root = NULL;
    }
    void insertIntoBST();
    void inOrderTrav();
};

void BST::inTrav(Node* root){
    if(root != NULL){
        inTrav(root->left);
        cout<<root->data<<" ";
        inTrav(root->right);
        return;
    }
    return;
}

void BST::inOrderTrav(){
    cout<<"In-order traversal:- "<<endl;
    inTrav(root);
    putchar('\n');
    return;
}

Node* BST::insert(Node* root, int  data){
    if(root != NULL){
        if(root->data > data){
            root->left = insert(root->left, data);
        }
        if(root->data < data){
            root->right = insert(root->right, data);
        }
        return root;
    }
    root = new Node(data);
    return root;
}

void BST::insertIntoBST(){
    int num;
    cout<<"Enter total number nodes in BST: ";
    cin>>num;
    for(int i = 0 ; i < num ; i++){
        int data;
        cout<<"Enter the data: ";
        cin>>data;
        root = insert(root, data);
    }
    cout<<"Binary Search Tree created!"<<endl;
}

int main(){
    BST* bst = new BST();
    bst->insertIntoBST();
    bst->inOrderTrav();
    return 0;
}