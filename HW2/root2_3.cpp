#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return (sqrt(7) + x) / 2;
}

int main() {
  double xOld, x = 0.0;
  const double epsilon = 1e-6;

  do {
    xOld = x;
    x = func(xOld);
  } while(fabs((x - xOld) * 100) > epsilon);

  cout << fixed << setprecision(6) << x << endl;
  
  return 0;
}