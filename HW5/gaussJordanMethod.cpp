#include <iostream>

using namespace std;

#define ROWS 3
#define COLS 3

void rowOperations(double matrixA[][COLS], double matrixB[], int pivot_row, int target_row, double factor) {
    for (int col = 0; col < COLS; ++col) {
      matrixA[target_row][col] -= factor * matrixA[pivot_row][col];
    }
    matrixB[target_row] -= factor * matrixB[pivot_row];
}

// Function to perform Gauss-Jordan elimination
void gaussJordan(double matrixA[][COLS], double matrixB[]) {
    for (int pivot_row = 0; pivot_row < ROWS; ++pivot_row) {
      // Make the diagonal element 1
      double pivot_element = matrixA[pivot_row][pivot_row];
      for (int col = 0; col < COLS; ++col) {
        matrixA[pivot_row][col] /= pivot_element;
      }
      matrixB[pivot_row] /= pivot_element;

      // Eliminate other elements in the same column
      for (int row = 0; row < ROWS; ++row) {
        if (row != pivot_row) {
          double factor = matrixA[row][pivot_row];
          rowOperations(matrixA, matrixB, pivot_row, row, factor);
        }
      }
    }
}

int main() {
    double matrixA[ROWS][COLS] = {
        {-2, 3, 1},
        {3, 4, -5},
        {1, -2, 1}
    };
    double matrixB[ROWS] = {9, 0, -4};

    gaussJordan(matrixA, matrixB);

    cout << "Solution:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << "x" << i+1 << " = " << matrixB[i] << endl;
    }

    return 0;
}