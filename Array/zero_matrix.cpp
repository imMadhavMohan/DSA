#include <bits/stdc++.h> 

// use 1st row & colm as indicator & address 1st row & 1st colm separately
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Check if the first row has a zero
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // Check if the first column has a zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    // Mark rows and columns for zeroing using first row and column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out marked rows
    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out marked columns
    for (int j = 1; j < m; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < n; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row
    if (firstRowHasZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle first column
    if (firstColHasZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    
	return matrix;
}