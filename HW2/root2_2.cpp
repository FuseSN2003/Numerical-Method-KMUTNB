#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return ((1.0 / 43.0) + x) / 2;
}

int main() {
  double xOld, x = 0.01;
  const double epsilon = 1e-6;

  do {
    xOld = x;
    x = func(xOld);
  } while(fabs((x - xOld) / x) * 100 > epsilon);

  cout << fixed << setprecision(6) << x << endl;
  
  return 0;
}