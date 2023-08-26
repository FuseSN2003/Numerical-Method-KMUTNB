#include <iostream>

using namespace std;

#define SIZE 3

void luDecomposition(double matrixA[SIZE][SIZE], double matrixB[SIZE], double result[SIZE]){
  double L[SIZE][SIZE] = {0};
  double U[SIZE][SIZE] = {0};
  double Y[SIZE];

  for(int i = 0; i < SIZE; i++) {
    for(int j = i; j < SIZE; j++) {
      double sum = 0;
      for(int k = 0; k < i; k++) {
        sum += L[j][k] * U[k][i];
      }
      L[j][i] = matrixA[j][i] - sum;
    }

    for(int j = i; j < SIZE; j++) {
      double sum = 0;
      for(int k = 0; k < i; k++) {
        sum += L[i][k] * U[k][j];
      }
      U[i][j] = (matrixA[i][j] - sum) / L[i][i];
    }
  }

  for(int i = 0; i < SIZE; i++) {
    double sum = 0;
    for(int j = 0; j < i; j++) {
      sum += L[i][j] * Y[j];
    }
    Y[i] = (matrixB[i] - sum) / L[i][i];
  }

  for(int i = SIZE - 1; i >= 0; i--) {
    double sum = 0;
    for(int j = i + 1; j < SIZE; j++) {
      sum += U[i][j] * result[j];
    }
    result[i] = (Y[i] - sum) / U[i][i];
  }
}

int main() {
  double matrixA[SIZE][SIZE] = {
    {-2, 3, 1},
    {3, 4, -5},
    {1, -2, 1},
  };
  double matrixB[SIZE] = {9, 0, -4};
  double result[SIZE];
  
  luDecomposition(matrixA, matrixB, result);

  for(int i = 0; i < SIZE; i++) {
    cout << "x" << i+1 << ": " << result[i] << endl;
  }
  
  return 0;
}