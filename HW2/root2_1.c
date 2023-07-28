#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double func(double x) {
  return pow(x, 4) - 13;
}

int main() {
  double xl = 1.5, xr = 2.0;
  double f_xl, f_xr, x1, f_x1;
  
  f_xl = func(xl);
  f_xr = func(xr);

  x1 = (xl * f_xr - xr * f_xl) / (f_xr - f_xl);
  f_x1 = func(x1);

  while(fabs(f_x1*f_xl/x1)*100 > EPSILON){
    f_xl = func(xl);
    f_xr = func(xr);
    
    x1 = (xl * f_xr - xr * f_xl) / (f_xr - f_xl);
    f_x1 = func(x1);

    if(f_x1*f_xr < 0){
      xl = x1;
    } else {
      xr = x1;
    }
  }

  printf("%.6f", x1);

  return 0;
}