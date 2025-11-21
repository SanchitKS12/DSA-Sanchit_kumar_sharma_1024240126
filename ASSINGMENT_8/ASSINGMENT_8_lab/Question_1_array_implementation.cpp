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

int searchRecursive(int tree[], int index, int n, int key) {
    if (index >= n || tree[index] == -1){
        return -1;
    } 

    if (tree[index] == key){
        return index;   
    }

    if (key < tree[index]){
        return searchRecursive(tree, 2 * index + 1, n, key);   
    }

    return searchRecursive(tree, 2 * index + 2, n, key);       
}


int main(){
    int tree[MAX];
    int n;

    cout << "Enter number of nodes in the binary tree: ";
    cin >> n;

    cout<<"use -1 for empty node"<< endl;
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

    int key,r1;
    cout<<"Enter key to be searched : ";
    cin>>key;

    r1=searchRecursive(tree,0,n,key);

    if(r1==-1){
        cout<<"Key not found in the tree"<<endl;
    }
    else{
        cout<<"Key found in the tree at the index :"<< r1 <<endl;
    }
}