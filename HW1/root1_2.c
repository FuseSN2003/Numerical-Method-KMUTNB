#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double func(double x){
  return pow(x, 4) - 13;
}

int main() {
  double xl = 1.5, xr = 2.0, xm;

  while(xr - xl >= EPSILON){
    xm = (xl + xr) / 2;

    if(func(xm) * func(xr) < 0) {
      xl = xm;
    } else {
      xr = xm;
    }
  }

  printf("%.6lf", xm);

  return 0;
}