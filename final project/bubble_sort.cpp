#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    int step = 1;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        cout << "Step " << step++ << ": ";
        printArray(arr);
        if (!swapped)
            break;
    }
    cout << "Final Sorted Array: ";
    printArray(arr);
}

int main() {
    int n, val;
    vector<int> data;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        data.push_back(val);
    }

    cout << "Original Array: ";
    printArray(data);
    bubbleSort(data);
    return 0;
}
