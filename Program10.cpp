#include <iostream>
using namespace std;

// Define structure for a node
struct Node {
    int data;        // Data part
    Node* next;      // Pointer to next node
};

// Global head pointer
Node* head = NULL;

// 1. Insert at Beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();   // Create new node
    newNode->data = value;        // Assign data
    newNode->next = head;         // Point to current head
    head = newNode;               // Make new node as head
}

// 2. Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {  // Traverse till last node
        temp = temp->next;
    }

    temp->next = newNode;         // Attach new node at end
}

// 3. Insert at Given Position
void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    // If inserting at first position
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to node before the desired position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid Position\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {

    insertAtBeginning(10);
    insertAtBeginning(5);

    insertAtEnd(20);
    insertAtEnd(30);

    insertAtPosition(15, 3);

    cout << "Linked List: ";
    display();

    return 0;
}
