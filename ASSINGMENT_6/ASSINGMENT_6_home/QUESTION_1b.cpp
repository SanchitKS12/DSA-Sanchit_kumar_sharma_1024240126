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

Node* insertAtBeginning(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtLast(Node* head, int x) {
    Node* newNode = new Node(x);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertBeforeNode(Node* head, int x, int nodeValue) {
    if (head == NULL) return NULL;

    Node* newNode = new Node(x);

    if (head->data == nodeValue) {
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != head && temp->next->data != nodeValue)
        temp = temp->next;

    if (temp->next == head) {
        cout << "Entered node is not present\n";
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int nodeValue) {
    if (head == NULL) return NULL;

    Node* temp = head;

    if (head->next == head && head->data == nodeValue) {
        delete head;
        return NULL;
    }

    if (head->data == nodeValue) {
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        Node* del = head;
        head = head->next;
        delete del;
        return head;
    }

    temp = head;
    while (temp->next != head && temp->next->data != nodeValue)
        temp = temp->next;

    if (temp->next == head) {
        cout << "Entered node is not present\n";
        return head;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

void searchNode(Node* head, int nodeValue) {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }

    int pos = 1;
    Node* temp = head;
    bool found = false;

    do {
        if (temp->data == nodeValue) {
            cout << "Entered Node is found at position : " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        cout << "Entered Node is not present\n";
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

    int choice;
    do {
        cout << endl << "Enter choice as per menu below:\n";
        cout << "1. Insertion at the beginning\n";
        cout << "2. Insertion at the end\n";
        cout << "3. Insertion before a node\n";
        cout << "4. Deletion of a specific node\n";
        cout << "5. Searching of a node\n";
        cout << "6. Display all node values\n";
        cout << "7. Exit\n";
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