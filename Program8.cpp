#include <iostream>
using namespace std;

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

// Insert element into queue
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }
}

// Remove element from queue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted: " << queue[front] << endl;
        front++;
    }
}

// Display queue elements
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
