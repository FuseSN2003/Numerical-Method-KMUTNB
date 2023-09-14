#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// f(x) = x * x - 7
int main() {
  const double epsilon = 1e-6;
  double x = 2.0;
  
  double f = pow(x, 2) - 7;
  double f_prime = 2 * x;

  double xNew = x - (f / f_prime);

  while(fabs((xNew - x) / xNew) * 100 > epsilon) {
    x = xNew;
    f = pow(x, 2) - 7;
    f_prime = 2 * x;
    xNew = x - (f / f_prime);
  }

  cout << fixed << setprecision(6) << x << endl;
  
  return 0;
}