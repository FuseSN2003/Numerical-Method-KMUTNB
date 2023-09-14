#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 4;
const double EPSILON = 1e-3;

// Function to calculate the dot product of two arrays
inline double dotProduct(const double a[], const double b[]) {
  double result = 0.0;
  for (int i = 0; i < N; i++) {
    result += a[i] * b[i];
  }
  return result;
}

// Function to perform matrix-vector multiplication
void matrixVectorMultiply(const double a[N][N], const double x[N], double result[N]) {
  for (int i = 0; i < N; i++) {
    result[i] = 0.0;
    for (int j = 0; j < N; j++) {
      result[i] += a[i][j] * x[j];
    }
  }
}

void conjugateGradientMethod(const double a[][N], const double b[N], double x[N]) {
  double r[N];
  double p[N];
  double Ap[N];
  int iteration = 0;

  matrixVectorMultiply(a, x, r);
  for (int i = 0; i < N; i++) {
    r[i] = b[i] - r[i];
    p[i] = r[i];
  }

  double rsold = dotProduct(r, r);

  do {
    iteration++;
    matrixVectorMultiply(a, p, Ap);
    double alpha = rsold / dotProduct(p, Ap);

    for (int i = 0; i < N; i++) {
      x[i] += alpha * p[i];
      r[i] -= alpha * Ap[i];
    }

    double rsnew = dotProduct(r, r);
    double beta = rsnew / rsold;

    for (int i = 0; i < N; i++) {
      p[i] = r[i] + beta * p[i];
    }

    rsold = rsnew;
  } while (sqrt(rsold) > EPSILON);
  cout << "Iteration: " << iteration << endl;
}

int main() {
  double a[N][N] = {
    {5, 2, 0, 0},
    {2, 5, 2, 0},
    {0, 2, 5, 2},
    {0, 0, 2, 5},
  };
  double b[N] = {12, 17, 14, 7};
  double x[N] = {0.0};

  conjugateGradientMethod(a, b, x);

  for (int i = 0; i < N; i++) {
    cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
  }

  return 0;
}
