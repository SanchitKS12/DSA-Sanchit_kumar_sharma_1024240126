#include<bits/stdc++.h>
using namespace std;

#define MAXLEN 100
int binaryTree[MAXLEN];

class BinaryTree{
    public:
    BinaryTree(){
        for(int i=0; i<MAXLEN; i++){
            binaryTree[i] = -1;
        }
    }

    void insertRoot(int val){
        binaryTree[1] = val;
    }

    void insertLeftNode(int indexP, int val){
        int left = 2 * indexP;
        if(left < MAXLEN){
            binaryTree[left] = val;
        }
        else{
            cout << "Out of range" << endl;
        }
    }

    void insertRightNode(int indexP, int val){
        int right = (2 * indexP) + 1;
        if(right < MAXLEN){
            binaryTree[right] = val;
        }
        else{
            cout << "Out of range" << endl;
        }
    }

    void preOrder(int index = 1){
        if((index >= MAXLEN) || (binaryTree[index] == -1)){
            return;
        }
        cout << binaryTree[index] << " ";
        preOrder(2*index);
        preOrder((2*index)+1);
    }

    void inOrder(int index = 1){
        if((index >= MAXLEN) || (binaryTree[index] == -1)){
            return;
        }
        inOrder(2*index);
        cout << binaryTree[index] << " ";
        inOrder((2*index)+1);
    }

    void postOrder(int index = 1){
        if((index >= MAXLEN) || (binaryTree[index] == -1)){
            return;
        }
        postOrder(2*index);
        postOrder((2*index)+1);
        cout << binaryTree[index] << " ";
    }
};

int main(){
    BinaryTree bt;
    int choice;
    do{
        cout << endl << "Enter:" << endl <<
        "1 to insert root" << endl <<
        "2 to insert at left" << endl <<
        "3 to insert at right" << endl <<
        "4 for preorder traversal" << endl <<
        "5 for inorder traversal" << endl <<
        "6 for postorder traversal" << endl <<
        "7 to exit" << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                int rootValue;
                cout << "Enter value of root : ";
                cin >> rootValue;
                bt.insertRoot(rootValue);
                break;
            }
            case 2:{
                int parentIndex;
                cout << "Enter parent index : ";
                cin >> parentIndex;
                int leftValue;
                cout << "Enter value of left node : ";
                cin >> leftValue;
                bt.insertLeftNode(parentIndex, leftValue);
                break;
            }
            case 3:{
                int parentIndex;
                cout << "Enter parent index : ";
                cin >> parentIndex;
                int rightValue;
                cout << "Enter value of right node : ";
                cin >> rightValue;
                bt.insertRightNode(parentIndex, rightValue);
                break;
            }
            case 4:{
                cout << "PreOrder Traversal : ";
                bt.preOrder();
                break;
            }
            case 5:{
                cout << "InOrder Traversal : ";
                bt.inOrder();
                break;
            }
            case 6:{
                cout << "PostOrder Traversal : ";
                bt.postOrder();
                break;
            }
            case 7:{
                cout << "Exiting..." << endl;
                break;
            }
            default:{
                cout << "Invalid choice" << endl;
            }
        }
    }
    while(choice != 7);
    return 0;
}