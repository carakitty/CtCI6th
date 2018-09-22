//
//  main.cpp
//  08_zeroMatrix
//  Write an algorithm such that if an element in an M*N matrix is 0, its entire row and column are set to zero.
//
//  Created by carakitty on 9/22/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// better solution on github which use the first column and row as the extra space to record the rows and columns to set zero
void setZeros(int ** matrix, int m, int n) {
    // use two array to record the row and column to set zero
    int * row = new int[m];
    int * column = new int[n];
    
    // initialize two array
    for (int i = 0; i < m; i++) row[i] = 0;
    for (int j = 0; j < n; j++) column[j] = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    
    // nullify rows and columns
    for (int i = 0; i < m; i++) {
        if (row[i] == 1) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (column[j] == 1) {
            for (int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

void print(int ** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows of the matrix: ";
    cin >> m;
    cout << "Enter the number of columns of the matrix: ";
    cin >> n;
    
    int ** matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "The original matrix is: " << endl;
    print(matrix, m, n);
    cout << "Matrix after setting to zeros: " << endl;
    setZeros(matrix, m, n);
    print(matrix, m, n);
    
    return 0;
}










































