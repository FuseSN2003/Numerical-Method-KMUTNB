#include <iostream>
#include <cmath>

const int N = 4; // Size of the matrix

// Function to calculate the dot product of two arrays
double dotProduct(double a[], double b[]) {
  double result = 0.0;
  for (int i = 0; i < N; i++) {
    result += a[i] * b[i];
  }
  return result;
}

// Function to perform matrix-vector multiplication
void matrixVectorMultiply(double A[N][N], double x[N], double result[N]) {
  for (int i = 0; i < N; i++) {
    result[i] = 0.0;
    for (int j = 0; j < N; j++) {
      result[i] += A[i][j] * x[j];
    }
  }
}

int main() {
  double A[N][N] = {
  {5, 2, 0, 0},
  {2, 5, 2, 0},
  {0, 2, 5, 2},
  {0, 0, 2, 5},
  };
  double b[N] = {12, 17, 14, 7};
  double x[N] = {0.0};
  double r[N]; // Residual vector
  double p[N]; // Search direction vector

  // Initialize residual vector r = b - A*x
  matrixVectorMultiply(A, x, r);
  for (int i = 0; i < N; i++) {
      r[i] = b[i] - r[i];
      p[i] = r[i];
  }

  double rsold = dotProduct(r, r);

  for (int iter = 0; iter < N; iter++) {
    double Ap[N];
    matrixVectorMultiply(A, p, Ap);
    double alpha = rsold / dotProduct(p, Ap);

    for (int i = 0; i < N; i++) {
        x[i] += alpha * p[i];
        r[i] -= alpha * Ap[i];
    }

    double rsnew = dotProduct(r, r);
    if (sqrt(rsnew) < 1e-6) {
        break;
    }

    for (int i = 0; i < N; i++) {
        p[i] = r[i] + (rsnew / rsold) * p[i];
    }
    rsold = rsnew;
  }

  std::cout << "Solution vector x:\n";
  for (int i = 0; i < N; i++) {
    std::cout << "x[" << i << "] = " << x[i] << std::endl;
  }

  return 0;
}
