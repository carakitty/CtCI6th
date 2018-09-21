//
//  main.cpp
//  07_rotateMatrix
//  Given an image represented by an N*N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this inplace?
//
//  Created by carakitty on 9/21/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

void rotateMatrix(int ** matrix, int n) {
    // rotate the layer from outside to inside anticlockwise
    for (int layer = 0; layer < n/2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int d = i - first;
            int temp = matrix[first][i];
            matrix[first][i] = matrix[i][last];
            matrix[i][last] = matrix[last][last-d];
            matrix[last][last-d] = matrix[last-d][first];
            matrix[last-d][first] = temp;
        }
    }
}

void printMatrix(int ** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter N for N*N matrix: ";
    cin >> n;
    int ** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    
    cout << "Input matrix:" << endl;
    printMatrix(matrix, n);
    cout << "Rotate matrix anticlockwise by 90 degrees: " << endl;
    rotateMatrix(matrix, n);
    printMatrix(matrix, n);
    
    return 0;
}
