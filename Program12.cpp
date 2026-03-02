#include <iostream>
using namespace std;

// Structure for Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Global head pointer
Node* head = NULL;

// 1. Insert at Beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    cout << "Inserted at beginning.\n";
}

// 2. Insert at End
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    cout << "Inserted at end.\n";
}

// 3. Insert at Position
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    cout << "Inserted at position " << pos << ".\n";
}

// 4. Delete from Beginning
void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    cout << "Deleted from beginning.\n";
}

// 5. Delete from End
void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    if (temp->next == NULL) {
        delete temp;
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;

    cout << "Deleted from end.\n";
}

// 6. Delete from Position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete temp;

    cout << "Deleted from position " << pos << ".\n";
}

// 7. Search
void search(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found.\n";
}

// 8. Display Forward
void displayForward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 9. Display Backward
void displayBackward() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Main Function
int main() {
    int choice, value, pos;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Search\n";
        cout << "8. Display Forward\n";
        cout << "9. Display Backward\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteFromPosition(pos);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 8:
                displayForward();
                break;

            case 9:
                displayBackward();
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    return 0;
}
