#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6
#define MIN 0
#define MAX 1e6

int main() {
  double x, n, xl = MIN, xr = MAX;
  double xm = (xl + xr) / 2;

  scanf("%lf %lf", &x, &n);

  while(fabs(pow(xm, n) - x) >= EPSILON){
    if(pow(xm, n) > x) {
      xr = xm;
    } else {
      xl = xm;
    }
    xm = (xl + xr) / 2;
  }

  printf("%.6lf", xm);

  return 0;
}