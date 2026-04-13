#include <stdio.h>

#define SIZE 10

int table[SIZE];

// Initialize table with -1 (empty)
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hash(key);

    // If collision, find next empty slot
    while (table[index] != -1) {
        index = (index + 1) % SIZE;
    }

    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search element
void search(int key) {
    int index = hash(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            printf("Element %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == start) break; // full loop
    }

    printf("Element %d not found\n", key);
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, table[i]);
    }
}

int main() {
    initialize();

    insert(23);
    insert(33);
    insert(43);
    insert(12);

    display();

    search(33);
    search(99);

    return 0;
}
