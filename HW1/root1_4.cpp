#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return pow(x, 2) - 7;
}

int main() {
  double xl = 0, xr = 10, xm;
  const double epsilon = 1e-6;

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