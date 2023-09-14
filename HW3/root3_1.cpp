#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
  return (1.0 / 4.0) + (x / 2.0);
}

int main() {
  double xOld = 0.00, xNew;
  const double epsilon = 1e-6;

  xNew = func(xOld);
  while(fabsl((xNew - xOld) / xNew) * 100 > epsilon){
    xOld = xNew;
    xNew = func(xOld);
  }

  cout << fixed << setprecision(6) << xNew << endl;
  
  return 0;
}