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
    bool search(Node* root, int);
    public:
    BST(){
        this->root = NULL;
    }
    void insertIntoBST();
    void inOrderTrav();
    void searchInBST();
};

bool BST::search(Node* root, int data){
    if(root != NULL){
        if(data == root->data){
            return true;
        }
        bool left = search(root->left, data);
        if(!left){
            bool right = search(root->right, data);
            if(right){
                return true;
            }
        }
        return left;
    }
    return false;
}
void BST::searchInBST(){
    int data;
    cout<<"Enter the data to be searched: ";
    cin>>data;
    bool ans = search(root, data);
    if(ans){
        cout<<data<<" was fount in the BST!"<<endl;
    }else{
        cout<<data<<" was not found in the BST!"<<endl;
    }
    return;
}

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
    bst->searchInBST();
    return 0;
}