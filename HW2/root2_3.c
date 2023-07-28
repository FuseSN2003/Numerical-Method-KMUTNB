#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double func(double x){
  return (sqrt(7) + x) / 2;
}

int main() {
    double xOld = 0, xNew;

    xNew = func(xOld);
    while(fabs((xNew - xOld) / xNew) * 100 > EPSILON){
      xOld = xNew;
      xNew = func(xOld);
    }
    printf("%.6f", xNew);

    return 0;
}