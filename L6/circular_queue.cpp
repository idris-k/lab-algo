#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularQueue {
private:
    CNode* rear;

public:
    CircularQueue() : rear(nullptr) {}

    // Enqueue operation
    void enqueue(int val) {
        CNode* newNode = new CNode(val);
        if (!rear) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued to circular queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (!rear) {
            cout << "Circular Queue Underflow!" << endl;
            return;
        }

        CNode* front = rear->next;
        if (rear == front) {
            cout << front->data << " dequeued from circular queue." << endl;
            delete front;
            rear = nullptr;
        } else {
            rear->next = front->next;
            cout << front->data << " dequeued from circular queue." << endl;
            delete front;
        }
    }

    // Peek front element
    void peek() {
        if (!rear) {
            cout << "Circular Queue is empty." << endl;
        } else {
            cout << "Front element is " << rear->next->data << endl;
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return rear == nullptr;
    }

    // Display all elements in circular queue
    void display() {
        if (!rear) {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        CNode* temp = rear->next;
        cout << "Circular Queue contents: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cq.peek();     // Should show 10
    cq.display();  // Should show 10 20 30

    cq.dequeue();  // Removes 10
    cq.display();  // Should show 20 30

    return 0;
}
