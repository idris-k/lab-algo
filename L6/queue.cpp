#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    QNode* front;
    QNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation (adds to rear)
    void enqueue(int val) {
        QNode* newNode = new QNode(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued to queue." << endl;
    }

    // Dequeue operation (removes from front)
    void dequeue() {
        if (!front) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        QNode* toDelete = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;
        if (!front) rear = nullptr;  // Queue is now empty
        delete toDelete;
    }

    // Peek at the front element
    void peek() {
        if (!front) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is " << front->data << endl;
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue from front to rear
    void display() {
        if (!front) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents (front to rear): ";
        QNode* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.peek();     // Should show 10
    queue.display();  // Should show 10 20 30

    queue.dequeue();  // Removes 10
    queue.display();  // Should show 20 30

    return 0;
}

