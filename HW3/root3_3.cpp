#include <iostream>
#include <math.h>

#define EPSILON 1e-6

using namespace std;

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

  cout << x;
  
  return 0;
}