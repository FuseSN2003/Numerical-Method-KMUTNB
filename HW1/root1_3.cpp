#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return 43 * x - 1;
}

int main() {
  const double epsilon = 1e-6;
  double xl = 0.02, xr = 0.03, xm;

  do {
    xm = (xl + xr) / 2;

    if(func(xm) * func(xr) > 0) {
      xr = xm;
    } else {
      xl = xm;
    }
  } while(fabs(xl - xr) > epsilon);

  cout << fixed << setprecision(6) << xm << endl;
  
  return 0;
}