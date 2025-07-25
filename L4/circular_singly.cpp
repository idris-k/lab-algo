#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

// Changed class name to reflect circular structure
class CircularLinkedList {
private:
    SNode* tail; // 🔄 Changed from head to tail pointer for circular tracking

public:
    // Constructor initializes tail instead of head
    CircularLinkedList() : tail(nullptr) {}

    // Modified to maintain circular link and update tail
    void addNode(int val) {
        SNode* newNode = new SNode(val);
        if (!tail) {
            // First node: points to itself
            tail = newNode;
            tail->next = tail;
        } else {
            // Insert after tail and update tail
            newNode->next = tail->next; // tail->next is head
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Updated to loop from head until back to head
    void display() {
    if (!tail) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    SNode* temp = tail->next; // Start from head
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next); // Loop until back to head
    cout << "(" << head->data << " again)" << endl;
}


    // Modified to handle circular structure and update tail/head when needed
  void deleteNode(int val) {
    if (!tail) return;

    SNode* curr = tail->next; // Start from head
    SNode* prev = tail;

    // Case: only one node
    if (tail == tail->next && tail->data == val) {
        delete tail;
        tail = nullptr;
        return;
    }

    // General deletion loop
    do {
        if (curr->data == val) {
            if (curr == tail->next) {
                // Deleting head
                tail->next = curr->next;
            }
            if (curr == tail) {
                // Deleting tail
                tail = prev;
            }
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next); // Loop until back to head
}


int main() {
    CircularLinkedList list; //  Class name changed

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);

    list.display(); // Output: 10 20 30

    list.deleteNode(20);
    list.display(); // Output: 10 30

    list.deleteNode(10);
    list.display(); // Output: 30

    list.deleteNode(30);
    list.display(); // Output: empty message

    return 0;
}
