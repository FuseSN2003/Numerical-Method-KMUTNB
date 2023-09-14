#include <iostream>
#include <cmath>
#include <iomanip>

#define SIZE 4

using namespace std;

void gaussSeidelMethod(double a[][SIZE], double b[], double x[]) {
  const double epsilon = 1e-3;
  double xNew[SIZE] = {0.0};
  bool error;
  int iteration = 0;
  
  do {
    iteration++;
    for (int i = 0; i < SIZE; i++) {
      double sum = 0.0;
      for (int j = 0; j < SIZE; j++) {
        if (j != i) {
          sum += a[i][j] * xNew[j];
        }
      }
      xNew[i] = (b[i] - sum) / a[i][i];
    }

    error = false;
    for (int i = 0; i < SIZE; i++) {
      if (fabs((xNew[i] - x[i]) / xNew[i]) * 100 > epsilon) {
        error = true;
        break;
      }
    }
    
    for (int i = 0; i < SIZE; i++) {
      x[i] = xNew[i];
    }
  } while (error);
  
  cout << "iteration: " << iteration << endl;
}

int main() {
  double a[SIZE][SIZE] = {
    {5, 2, 0, 0},
    {2, 5, 2, 0},
    {0, 2, 5, 2},
    {0, 0, 2, 5},
  };
  double b[SIZE] = {12, 17, 14, 7};
  double x[SIZE] = {0.0};

  gaussSeidelMethod(a, b, x);

  for (int i = 0; i < SIZE; i++) {
    cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
  }
  
  return 0;
}