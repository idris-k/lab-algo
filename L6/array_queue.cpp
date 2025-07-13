#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    ArrayQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        cout << val << " enqueued to array queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from array queue." << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Peek front
    void peek() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is " << arr[front] << endl;
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Display queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue aq(5);  // Capacity = 5

    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);

    aq.peek();     // Should show 10
    aq.display();  // Should show 10 20 30

    aq.dequeue();  // Removes 10
    aq.display();  // Should show 20 30

    return 0;
}
