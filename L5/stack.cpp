#include <iostream>
using namespace std;

struct SNode {
    int data;
    SNode* next;
    SNode(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    SNode* top;  // Top of the stack

public:
    Stack() : top(nullptr) {}

    // Push operation (adds to top)
    void push(int val) {
        SNode* newNode = new SNode(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack." << endl;
    }

    // Pop operation (removes from top)
    void pop() {
        if (!top) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        SNode* toDelete = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete toDelete;
    }

    // Peek at the top element
    void peek() {
        if (!top) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is " << top->data << endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack from top to bottom
    void display() {
        if (!top) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents (top to bottom): ";
        SNode* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.peek();     // Should show 30
    stack.display();  // Should show 30 20 10

    stack.pop();      // Removes 30
    stack.display();  // Should show 20 10

    return 0;
}
