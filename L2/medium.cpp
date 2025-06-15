#include <iostream>
#include <vector>
using namespace std;

//rotate matrix by 90,180 or 270 degree
// Function to display a matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

// Function to rotate the matrix by a specified angle
bool rotateMatrix(vector<vector<int>>& mat, int angle) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));

    if (angle == 90) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] = mat[n - j - 1][i];
    } 
    else if (angle == 180) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] = mat[n - i - 1][n - j - 1];
    } 
    else if (angle == 270) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] = mat[j][n - i - 1];
    } 
    else {
        // invalid input
        return false;
    }

    mat = res; // update the original matrix
    return true;
}

int main() {
    // Original matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(mat);

    int angle;
    cout << "\nEnter rotation angle (90, 180, or 270): ";
    cin >> angle;

    if (rotateMatrix(mat, angle)) {
        cout << "\nRotated Matrix (" << angle << " degrees):\n";
        printMatrix(mat);
    } else {
        cout << "\n Invalid rotation angle entered. Please enter 90, 180, or 270.\n";
    }

    return 0;
}
