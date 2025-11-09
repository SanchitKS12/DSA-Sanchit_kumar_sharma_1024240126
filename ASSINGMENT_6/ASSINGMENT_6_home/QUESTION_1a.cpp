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

Node* convertArrToLL(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* back = head;
    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i], nullptr, back);
        back->next = newNode;
        back = newNode;
    }
    return head;
}

Node* insertAtBeginning(Node* head, int x) {
    Node* newHead = new Node(x);
    if (head == NULL) return newHead;
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}

Node* insertAtLast(Node* head, int x) {
    Node* newTail = new Node(x);
    if (head == NULL) return newTail;
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newTail;
    newTail->prev = temp;
    return head;
}

Node* insertBeforeNode(Node* head, int x, int nodeValue) {
    Node* newNode = new Node(x);
    if (head == NULL) return newNode;

    if (head->data == nodeValue) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != nodeValue) temp = temp->next;

    if (temp == NULL) {
        cout << "Entered Node is not present\n";
        return head;
    }

    Node* prevNode = temp->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = temp;
    temp->prev = newNode;

    return head;
}

Node* deleteNode(Node* head, int nodeValue) {
    if (head == NULL) return head;

    if (head->data == nodeValue) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = nullptr;
        delete temp;
        return head;
    }

    Node* curr = head;
    while (curr != NULL && curr->data != nodeValue) curr = curr->next;

    if (curr == NULL) {
        cout << "Entered Node is not present\n";
        return head;
    }

    Node* back = curr->prev;
    Node* front = curr->next;

    if (back != NULL) back->next = front;
    if (front != NULL) front->prev = back;

    delete curr;
    return head;
}

void searchNode(Node* head, int nodeValue) {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    int pos = 1;
    Node* temp = head;
    while (temp != NULL && temp->data != nodeValue) {
        pos++;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Entered Node is not present\n";
        return;
    }
    cout << "Entered Node is found at position : " << pos << endl;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    Node* head = convertArrToLL(arr, 7);
    int choice;
    do {
        cout << endl << "Enter choice as per menu below : " << endl;
        cout << "1. Insertion at the beginning" << endl;
        cout << "2. Insertion at the end" << endl;
        cout << "3. Insertion before a node" << endl;
        cout << "4. Deletion of a specific node" << endl;
        cout << "5. Searching of a node" << endl;
        cout << "6. Display all node values" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter node value: ";
            int value;
            cin >> value;
            head = insertAtBeginning(head, value);
            break;
        }
        case 2: {
            cout << "Enter node value: ";
            int value;
            cin >> value;
            head = insertAtLast(head, value);
            break;
        }
        case 3: {
            cout << "Enter existing node value (before which to insert): ";
            int nodeValue;
            cin >> nodeValue;
            cout << "Enter new node value: ";
            int value;
            cin >> value;
            head = insertBeforeNode(head, value, nodeValue);
            break;
        }
        case 4: {
            cout << "Enter node value to delete: ";
            int nodeValue;
            cin >> nodeValue;
            head = deleteNode(head, nodeValue);
            break;
        }
        case 5: {
            cout << "Enter node value to search: ";
            int nodeValue;
            cin >> nodeValue;
            searchNode(head, nodeValue);
            break;
        }
        case 6: {
            print(head);
            break;
        }
        }
    } while (choice != 7);

    return 0;
}