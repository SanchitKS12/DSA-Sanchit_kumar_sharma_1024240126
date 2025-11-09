#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArrToDLL(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* back = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i], nullptr, back);
        back->next = newNode;
        back = newNode;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int count(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    Node* head = convertArrToDLL(arr, 7);
    print(head);
    cout << "size = " << count(head);
    return 0;
}