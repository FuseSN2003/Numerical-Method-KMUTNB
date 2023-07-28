#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double func(double x){
  return 43 * x - 1;
}

int main() {
  double xl = 0.02, xr = 0.03, xm;

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