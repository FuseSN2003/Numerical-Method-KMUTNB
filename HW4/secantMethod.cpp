#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define EPSILON 1e-6

// f(x) = x^2 - 7
double func(double x) {
  return pow(x, 2) - 7;
}

int main() {
  double x0 = 1.0, x1 = 1.5, xi, f0, f1;

  do {
    f0 = func(x0);
    f1 = func(x1);

    xi = x0 - (f0 * (x0 - x1)) / (f0 - f1);

    x0 = x1;
    x1 = xi;

  } while (fabs(x1-x0) > EPSILON);

  cout << fixed << setprecision(6) << xi << endl;
  
  return 0;
}