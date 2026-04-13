// Quadratic Probing Based
#include <stdio.h>
#define SIZE 10

int table[SIZE];

// Initialize hash table
void init() {
    for(int i = 0; i < SIZE; i++) {
        table[i] = -1;   // -1 means empty
    }
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (table[(index + i*i) % SIZE] != -1 && i < SIZE) {
        i++;
    }

    if (i == SIZE) {
        printf("Hash table is full\n");
    } else {
        table[(index + i*i) % SIZE] = key;
        printf("Inserted %d at index %d\n", key, (index + i*i) % SIZE);
    }
}

// Search using Quadratic Probing
void search(int key) {
    int index = hash(key);
    int i = 0;

    while (table[(index + i*i) % SIZE] != -1 && i < SIZE) {
        if (table[(index + i*i) % SIZE] == key) {
            printf("Key %d found at index %d\n", key, (index + i*i) % SIZE);
            return;
        }
        i++;
    }

    printf("Key %d not found\n", key);
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("%d -> EMPTY\n", i);
        else
            printf("%d -> %d\n", i, table[i]);
    }
}

// Main function
int main() {
    init();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    search(43);
    search(50);

    return 0;
}
