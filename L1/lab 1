#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    string contact;
    string email;
};

int main() {
    const int numStudents = 5;
    Student students[numStudents];

    // Input student data
    cout << "Enter data for 5 students:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore(); // clear newline character from buffer

        cout << "Contact: ";
        getline(cin, students[i].contact);

        cout << "Email: ";
        getline(cin, students[i].email);
    }

    // Display student data
    cout << "\nStored Student Data:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Contact: " << students[i].contact << endl;
        cout << "Email: " << students[i].email << endl;
    }

    return 0;
}
