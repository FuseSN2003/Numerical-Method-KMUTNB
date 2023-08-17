#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define EPSILON 1e-6

// f(x) = x * x - 7
int main() {
  double x = 2.0;
  
  double f = pow(x, 2) - 7;
  double f_prime = 2 * x;

  double xNew = x - (f / f_prime);

  while(fabs((xNew - x) / xNew) * 100 > EPSILON) {
    x = xNew;
    f = pow(x, 2) - 7;
    f_prime = 2 * x;
    xNew = x - (f / f_prime);
  }

  cout << fixed << setprecision(6) << x << endl;
  
  return 0;
}