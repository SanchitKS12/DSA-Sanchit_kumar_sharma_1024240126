#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void InsertionAtBeginning(int a) {
        Node* newNode = new Node{a, head};
        head = newNode;
        cout << a << " Insertion at the beginning.\n";
    }
    //         head = newNode;
    //     } else {
    //         Node* temp = head;
    //         while (temp->next) temp = temp;
    //         temp->next = newNode;
    //     }
    //     cout << val << " inserted at the end.\n";
    // }

    void InsertionAtEnd(int a) {
        Node* newNode = new Node{a, nullptr};
        if(!head){
            head=newNode;
        }
        else {
            Node* temp = head;
            while(temp->next) temp= temp->next;
            temp->next = newNode;
        }
        cout << a << "Insertion at end.\n";
    }

    void InsertionAtBefore(int valueToInsert,int nodeValue) {
        if (!head) {
            cout << "List is empty. Cannot insert before " << nodeValue <<endl;
            return;
        }
        if (head->data == nodeValue) {
            InsertionAtBeginning(valueToInsert);
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != nodeValue) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) {
            cout << "Node value not found. " << nodeValue <<endl;
            return;
        }
        Node* newNode = new Node{valueToInsert, curr};
        prev->next = newNode;
        cout << valueToInsert << " inserted before node " << nodeValue << ".\n";
    }

    void InsertionAfter(int valueToInsert, int nodeValue) {
        if (!head) {
            cout << "List is empty. Cannot insert after " << nodeValue << endl;
            return;
        }
        Node* curr = head;
        while (curr && curr->data != nodeValue) {
            curr = curr->next;
        }
        if (!curr) {
            cout << "Node value not found: " << nodeValue << endl;
            return;
        }
        Node* newNode = new Node{valueToInsert, curr->next};
        curr->next = newNode;
        cout << valueToInsert << " Insertion after node " << nodeValue << endl;
    } 

    void DeletionFromBeginning() {
        if (!head) {
            cout << "List is empty, deletion is unsuccesfulll.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    void DeletionFromEnd() {
        if (!head) {
            cout << "List is empty, deletion unsuccessful.\n";
            return;
        }
        if (!head->next) {
            cout << head->data << " deleted from the end.\n";
            delete head;
            head = nullptr;
            return;
        }
    }

    void DeletionOfSpecificNode(int nodeValue) {
        if (!head) {
            cout <<"List making unsuccesful"<<endl;
        }
         if (head->data == nodeValue) {
            DeletionFromBeginning();
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while (curr && curr->data != nodeValue) {
            prev=curr;
            curr=curr->next;
        }
        if (!curr) {
        cout << "Node " << nodeValue << " not found, deletion was unsuccessfull." << endl;
        return;
        }
        prev->next = curr->next;
        cout << curr->data << " deleted from the list." << endl;
        delete curr;     
    }
    void Search(int b){
        
    } 
};