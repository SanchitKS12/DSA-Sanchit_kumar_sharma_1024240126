#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

//Recursive Search(Search1)
Node* Search1(Node* root, int key){
    if(root == nullptr || root->data){
        return root;
    }
    if(key > root->data){
        return Search1(root->left, key);
    }
    if(key < root->data){
         return Search1(root->right, key);
    }
}

//Non Recursive(Search 2)
Node* Search2(Node* root, int key){
     while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

Node* FindMax(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    while(root->right != nullptr){
        root=root->right;
    }
    return root;
}

Node* FindMin(Node* root){
    if(root ==nullptr){
        return nullptr;
    }
    while(root->left != nullptr){
        root=root->left;
    }
    return root;
}

int main(){
    int x;
    int key;
    cout << "Enter total value :";
    cin >> x;
    Node* root=nullptr;
    int arr[x];
    cout << "Enter Node Value :" << endl;
    for(int  i=0; i<x; i++){
        root=insert(root,arr[i]);
    }
    cout<<"Enter the value to search :"<<endl;
    cin >> key; 
    return 0;
}