#include <iostream>
#include <math.h>
using namespace std;

#define EPSILON 1e-6

double func(double x) {
  return (1.0 / 4.0) + (x / 2.0);
}

int main() {
  double xOld = 0.00, xNew;

  xNew = func(xOld);
  while(fabsl((xNew - xOld) / xNew) * 100 > EPSILON){
    xOld = xNew;
    xNew = func(xOld);
  }

  cout << xNew << endl;
  
  return 0;
}