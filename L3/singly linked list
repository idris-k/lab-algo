#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    SNode* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void addNode(int val) {
        SNode* newNode = new SNode(val);
        if (!head) {
            head = newNode;
        } else {
            SNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        SNode* temp = head;
        cout << "Singly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNode(int val) {
        if (!head) return;

        if (head->data == val) {
            SNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        SNode* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            SNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);

    list.display();

    list.deleteNode(20);
    list.display();

    return 0;
}
