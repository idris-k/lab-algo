#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    // Add root node
    void add_root(string name) {
        if (!root)
            root = new Node(name);
        else
            cout << "Root already exists!" << endl;
    }

    // Find a node by name (recursive)
    Node* find(Node* current, const string& target) {
        if (!current) return nullptr;
        if (current->name == target) return current;

        Node* leftResult = find(current->left, target);
        if (leftResult) return leftResult;

        return find(current->right, target);
    }

    // Find the parent of a given node (by child name)
    Node* find_parent(Node* current, const string& child_name) {
        if (!current) return nullptr;

        if ((current->left && current->left->name == child_name) ||
            (current->right && current->right->name == child_name)) {
            return current;
        }

        Node* left = find_parent(current->left, child_name);
        if (left) return left;

        return find_parent(current->right, child_name);
    }

    // Add left child by parent name
    void left(const string& parent_name, const string& child_name) {
        Node* parent = find(root, parent_name);
        if (!parent) {
            cout << "Parent node \"" << parent_name << "\" not found!" << endl;
            return;
        }
        if (parent->left) {
            cout << "Left child already exists for \"" << parent_name << "\"!" << endl;
            return;
        }
        parent->left = new Node(child_name);
    }

    // Add right child by parent name
    void right(const string& parent_name, const string& child_name) {
        Node* parent = find(root, parent_name);
        if (!parent) {
            cout << "Parent node \"" << parent_name << "\" not found!" << endl;
            return;
        }
        if (parent->right) {
            cout << "Right child already exists for \"" << parent_name << "\"!" << endl;
            return;
        }
        parent->right = new Node(child_name);
    }

    // Remove a node by name (only if it's a leaf)
    void remove(const string& name) {
        if (!root) {
            cout << "Tree is empty." << endl;
            return;
        }

        if (root->name == name) {
            if (!root->left && !root->right) {
                delete root;
                root = nullptr;
                cout << "Root node \"" << name << "\" removed." << endl;
            } else {
                cout << "Cannot remove root node with children!" << endl;
            }
            return;
        }

        Node* parent = find_parent(root, name);
        if (!parent) {
            cout << "Node \"" << name << "\" not found!" << endl;
            return;
        }

        // Check if left child
        if (parent->left && parent->left->name == name) {
            if (!parent->left->left && !parent->left->right) {
                delete parent->left;
                parent->left = nullptr;
                cout << "Node \"" << name << "\" removed from left of \"" << parent->name << "\"." << endl;
            } else {
                cout << "Node \"" << name << "\" is not a leaf and cannot be removed!" << endl;
            }
            return;
        }

        // Check if right child
        if (parent->right && parent->right->name == name) {
            if (!parent->right->left && !parent->right->right) {
                delete parent->right;
                parent->right = nullptr;
                cout << "Node \"" << name << "\" removed from right of \"" << parent->name << "\"." << endl;
            } else {
                cout << "Node \"" << name << "\" is not a leaf and cannot be removed!" << endl;
            }
            return;
        }

        cout << "Unexpected error during removal." << endl;
    }

    // Display a node's children
    void display(const string& name) {
        Node* node = find(root, name);
        if (!node) {
            cout << "Node \"" << name << "\" not found!" << endl;
            return;
        }

        cout << "Node: " << node->name << endl;

        if (node->left)
            cout << "  Left child: " << node->left->name << endl;
        else
            cout << "  Left child: None" << endl;

        if (node->right)
            cout << "  Right child: " << node->right->name << endl;
        else
            cout << "  Right child: None" << endl;
    }

    // Display with parent info
    void display_with_parent(const string& name) {
        Node* node = find(root, name);
        if (!node) {
            cout << "Node \"" << name << "\" not found!" << endl;
            return;
        }

        Node* parent = find_parent(root, name);

        cout << "Node: " << node->name << endl;
        if (parent)
            cout << "  Parent: " << parent->name << endl;
        else
            cout << "  Parent: None (root)" << endl;

        if (node->left)
            cout << "  Left child: " << node->left->name << endl;
        else
            cout << "  Left child: None" << endl;

        if (node->right)
            cout << "  Right child: " << node->right->name << endl;
        else
            cout << "  Right child: None" << endl;
    }
};
int main() {
    Tree tree_add;

    tree_add.add_root("A");
    tree_add.left("A", "B");
    tree_add.right("A", "C");
    tree_add.left("B", "D");
    tree_add.right("B", "E");
    tree_add.left("C", "F");
    tree_add.right("C", "G");

    cout << "\n-- Displaying Nodes --" << endl;
    tree_add.display("A");
    tree_add.display("B");
    tree_add.display("C");

    cout << "\n-- Displaying with Parent Info --" << endl;
    tree_add.display_with_parent("D");
    tree_add.display_with_parent("E");

    cout << "\n-- Attempting Removals --" << endl;
    tree_add.remove("E");  //  Leaf node
    tree_add.remove("B");  //  Not a leaf
    tree_add.remove("A");  //  Root with children

    cout << "\n-- Display B after E removed --" << endl;
    tree_add.display("B");

    return 0;
}
