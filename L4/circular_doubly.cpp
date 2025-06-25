#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    DNode* head;
    DNode* tail; // + Added tail pointer

public:
    CircularDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode; //  Move tail to the new node
        }
    }

    void display() {
        if (!head) {
            cout << "Circular Doubly Linked List is empty." << endl;
            return;
        }

        DNode* temp = head;
        cout << "Circular Doubly Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(" << head->data << " again)" << endl;
    }

    void deleteNode(int val) {
        if (!head) return;

        DNode* temp = head;
        do {
            if (temp->data == val) {
                if (temp == head && temp == tail) {
                    // Only one node in the list
                    delete temp;
                    head = tail = nullptr;
                    return;
                }

                // Re-link neighbors
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                // Update head or tail if necessary
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;

                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
};
int main() {
    CircularDoublyLinkedList list;

    list.addNode(100);
    list.addNode(200);
    list.addNode(300);

    list.display();         // 100 200 300
    list.deleteNode(200);
    list.display();         // 100 300
    list.deleteNode(100);
    list.display();         // 300
    list.deleteNode(300);
    list.display();         // empty

    return 0;
}
;
