#include <iostream>
#include <iomanip>

using namespace std;

#define ROWS 3

using Matrix = double[ROWS][ROWS];

// Function to perform matrix multiplication
void matrixMultiplication(const Matrix& matrixA, const Matrix& matrixB, Matrix& resultMatrix) {
  const int Cols = 1;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < Cols; j++) {
      resultMatrix[i][j] = 0.0;
      for (int k = 0; k < ROWS; k++) {
        resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}

// Function to perform matrix inversion
void matrixInversion(const Matrix& matrixA, const Matrix& matrixB, Matrix& resultMatrix) {
  // Copy matrixA to another matrix
  Matrix matrix;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < ROWS; j++) {
        matrix[i][j] = matrixA[i][j];
    }
  }

  // Create an identity matrix
  Matrix identityMatrix;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < ROWS; j++) {
      identityMatrix[i][j] = (i == j) ? 1.0 : 0.0;
    }
  }

  // Gauss Elimination
  for (int i = 0; i < ROWS; i++) {
    double pivot_inv = 1.0 / matrix[i][i];

    for (int j = 0; j < ROWS; j++) {
      matrix[i][j] *= pivot_inv;
      identityMatrix[i][j] *= pivot_inv;
    }

    for (int j = 0; j < ROWS; j++) {
      if (j != i) {
        double factor = matrix[j][i];

        for (int k = 0; k < ROWS; k++) {
          identityMatrix[j][k] -= factor * identityMatrix[i][k];
          matrix[j][k] -= factor * matrix[i][k];
        }
      }
    }
  }
  matrixMultiplication(identityMatrix, matrixB, resultMatrix);
}

int main() {
  // Initialize matrix A
  Matrix matrixA = {
    {-9, 7, -19},
    {14, -13, -6},
    {16, 1, -4}
  };

  // Initialize matrix B
  Matrix matrixB = {
    {4000},
    {1200},
    {2350}
  };

  // Create a matrix to store the result
  Matrix resultMatrix;

  matrixInversion(matrixA, matrixB, resultMatrix);

  // Print the result matrix
  for (int i = 0; i < 3; i++) {
    cout << "x" << i+1 << " = " << resultMatrix[i][0] << endl;
  }

  return 0;
}