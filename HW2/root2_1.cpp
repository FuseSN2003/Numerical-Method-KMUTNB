#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return pow(x, 4) - 13;
}

int main() {
  double xl = 1.5, xr = 2.0, x1;
  const double epsilon = 1e-6;

  do {
    x1 = (xl * func(xr) - xr * func(xl)) / (func(xr) - func(xl));

    if(func(x1) * func(xr) > 0) {
      xr = x1;
    } else {
      xl = x1;
    }
  } while(fabs(func(x1)* func(xl) / x1) * 100 > epsilon);

  cout << fixed << setprecision(6) << x1 << endl;
  
  return 0;
}