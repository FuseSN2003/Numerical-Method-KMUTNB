#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x, double n) {
  return pow(x, n) - x;
}

int main() {
  double x, n, xl = 0, xr = 1e6, xm;
  const double epsilon = 1e-6;

  cin >> x;
  cin >> n;

  do {
    xm = (xl + xr) / 2;

    if(pow(xm, n) > x) {
      xr = xm;
    } else {
      xl = xm;
    }
  } while(fabs(pow(xm, n) - x) > epsilon);

  cout << fixed << setprecision(4) << xm << endl;
  
  return 0;
}