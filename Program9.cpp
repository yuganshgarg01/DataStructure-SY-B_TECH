#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value)
{
    // Overflow condition
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        // First insertion
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }
}

// Dequeue operation
void dequeue()
{
    // Underflow condition
    if (front == -1)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted: " << queue[front] << endl;

        // Only one element present
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

// Display operation
void display()
{
    if (front == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}

