#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToCLL(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* move = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        move->next = newNode;
        move = newNode;
    }
    move->next = head;
    return head;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; 
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    Node* head = convertArrToCLL(arr, 5);
    print(head);
    return 0;
}