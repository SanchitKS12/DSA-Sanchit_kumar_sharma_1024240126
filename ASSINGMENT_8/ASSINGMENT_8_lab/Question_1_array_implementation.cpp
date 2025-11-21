#include<iostream>
using namespace std;

#define MAX 100

void preorder(int tree[], int index, int n){
    if(index>=n || tree[index]==-1){
        return;
    }
    
    cout<<tree[index]<<" ";
    preorder(tree, 2*index+1, n);   //Left subtree
    preorder(tree, 2*index+2, n);   //Right subtree
}

void inorder(int tree[], int index, int n){
    if(index>=n || tree[index]==-1){
        return;
    }

    inorder(tree, 2*index+1, n);
    cout<<tree[index]<< " ";
    inorder(tree, 2*index+2, n);
}

void postorder(int tree[], int index, int n){
    if(index>=n || tree[index]==-1){
        return;
    }

    postorder(tree, 2*index+1, n);
    postorder(tree, 2*index+2, n);
    cout<<tree[index]<< " ";
}

int main(){
    int tree[MAX];
    int n;

    cout << "Enter number of nodes in the binary tree: ";
    cin >> n;

    cout<<"use -1 for empty node";
    cout<< "Enter the elements :"<< endl;
    for(int i=0; i<=n; i++){
        cin>>tree[i];
    }
    cout<<endl;

    cout<<"Preorder transversal :";
    preorder(tree,0,n);
    cout<<endl;

    cout<<"Inorder transversal :";
    inorder(tree,0,n);
    cout<<endl;

    cout<<"Postorder transversal :";
    postorder(tree,0,n);
    cout<<endl;
    
}