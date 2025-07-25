#include <bits/stdc++.h>
using namespace std;

//rotate clockwise by 3

// Function to rotate a matrix represented by a vector of vectors
void rotateMatrix(vector<vector<int>>& mat, int k) {
  
    int m = mat.size();
    int n = mat[0].size();
  
    int row = 0, col = 0;
    int prev, curr;
    
     // ✅ New outer loop: repeat the rotation process k times
    for (int step = 0; step < k; step++) {
        int row = 0, col = 0;
        int r = m, c = n; 

    // Rotate the matrix in layers
    while (row < r && col < c) {
        if (row + 1 == r || col + 1 == c)
            break;

        // Store the first element of the next row
        prev = mat[row + 1][col];

        // Move elements of the first row
        for (int i = col; i < c; i++) {
            curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        // Move elements of the last column
        for (int i = row; i < r; i++) {
            curr = mat[i][c - 1];
            mat[i][c - 1] = prev;
            prev = curr;
        }
        c--;

        // Move elements of the last row
        if (row < r) {
            for (int i = c - 1; i >= col; i--) {
                curr = mat[r - 1][i];
                mat[r - 1][i] = prev;
                prev = curr;
            }
        }
        r--;

        // Move elements of the first column
        if (col < c) {
            for (int i = r - 1; i >= row; i--) {
                curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotateMatrix(mat, 3);

    // Print the rotated matrix
    for (auto& r : mat) {
        for (int val : r)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
