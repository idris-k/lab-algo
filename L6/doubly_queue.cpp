#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedQueue {
private:
    DNode* front;
    DNode* rear;

public:
    DoublyLinkedQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue (add to rear)
    void enqueue(int val) {
        DNode* newNode = new DNode(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued to queue." << endl;
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (!front) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        DNode* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;

        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;  // queue is now empty
        }

        delete temp;
    }

    // Dequeue from rear (optional)
    void dequeueBack() {
        if (!rear) {
            cout << "Queue Underflow at rear!" << endl;
            return;
        }

        DNode* temp = rear;
        cout << rear->data << " dequeued from rear of queue." << endl;
        rear = rear->prev;

        if (rear) {
            rear->next = nullptr;
        } else {
            front = nullptr;  // queue is now empty
        }

        delete temp;
    }

    // Peek front
    void peekFront() {
        if (!front)
            cout << "Queue is empty." << endl;
        else
            cout << "Front element: " << front->data << endl;
    }

    // Peek rear
    void peekRear() {
        if (!rear)
            cout << "Queue is empty." << endl;
        else
            cout << "Rear element: " << rear->data << endl;
    }

    // Display the queue from front to rear
    void display() {
        if (!front) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents (front to rear): ";
        DNode* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    DoublyLinkedQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.peekFront();  // show 10
    queue.peekRear();   // show 30
    queue.display();    // 10 20 30

    queue.dequeue();    // Removes 10
    queue.display();    // 20 30

    queue.dequeueBack(); // Removes 30
    queue.display();     // 20

    return 0;
}
