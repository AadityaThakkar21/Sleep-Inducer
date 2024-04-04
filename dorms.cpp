#include <iostream>
#include <string>
using namespace std;

struct Node {
    string dormName;
    int capacity;
    Node* next;
};

void insertNode(Node*& head, string dormName, int capacity) {
    Node* newNode = new Node;
    newNode->dormName = dormName;
    newNode->capacity = capacity;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "Dorm Name: " << temp->dormName << ", Capacity: " << temp->capacity << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
    insertNode(head, "Eden", 20);
    insertNode(head, "Ares", 10);
    insertNode(head, "Old Residence", 30);
    insertNode(head, "North Residence", 15);
    display(head);

    return 0;
}
