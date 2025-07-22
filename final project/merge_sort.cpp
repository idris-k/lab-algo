#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

void merge(vector<int>& arr, int left, int mid, int right, int& step) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "Step " << step++ << ": ";
    printArray(arr);
}

void mergeSort(vector<int>& arr, int left, int right, int& step) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, step);
        mergeSort(arr, mid + 1, right, step);
        merge(arr, left, mid, right, step);
    }
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
    int step = 1;
    mergeSort(data, 0, data.size() - 1, step);
    cout << "Final Sorted Array: ";
    printArray(data);
    return 0;
}
