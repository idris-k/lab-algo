#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void addNode(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int val) {
        DNode* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }
};

int main() {
    DoublyLinkedList list;

    list.addNode(100);
    list.addNode(200);
    list.addNode(300);

    list.display();

    list.deleteNode(200);
    list.display();

    return 0;
}
