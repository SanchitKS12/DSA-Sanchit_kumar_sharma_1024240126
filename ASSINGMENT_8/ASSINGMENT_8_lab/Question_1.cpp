#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=nullptr;

    }
};

void preorderTransversal(Node* root){
    if(root == nullptr){
        return;
    }

    cout<< root->data << " ";

    preorderTransversal(root->left);
    preorderTransversal(root->right);

}

void postorderTransversal(Node* root){
    if(root == nullptr){
        return;
    }

    postorderTransversal(root->left);
    postorderTransversal(root->right);

    cout<< root->data << " ";

}

void inorderTransversal(Node* root){
    if(root == nullptr){
        return;
    }

    inorderTransversal(root->left);

    cout<< root->data << " ";

    inorderTransversal(root->right);

}

int main(){
    cout<<"please enter the root value :"<< endl
    return 0;
}