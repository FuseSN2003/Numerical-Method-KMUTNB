#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 4;
const double EPSILON = 1e-3;

void jacobiMethod(double a[][N], double b[], double x[]) {
  double xNew[N] = {0.0};
  bool error;
  int iteration = 0;
  
  do {
    iteration++;
    for(int i = 0; i < N; i++) {
      double sum = 0.0;
      for(int j = 0; j < N; j++) {
        if(j != i) {
          sum += a[i][j] * x[j];
        }
      }
      xNew[i] = (b[i] - sum) / a[i][i];
    }

    error = false;
    for(int i = 0; i < N; i++) {
      if(fabs((xNew[i] - x[i]) / xNew[i]) * 100 > EPSILON) {
        error = true;
        break;
      }
    }
    
    for(int i = 0; i < N; i++) {
      x[i] = xNew[i];
    }
  } while(error);
  
  cout << "iteration: " << iteration << endl;
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

  jacobiMethod(a, b, x);

  for(int i = 0; i < N; i++) {
    cout << "x" << i+1 << " = " << fixed << setprecision(6) << x[i] << endl;
  }
  
  return 0;
}