#include <stdio.h>

double func(double x) {
  return 43 * x - 180;
}

int main() {
  double x = 0, y, z;

  for(x = 0; x <= 10; x++){
    y = func(x);
    z = func(x+1);
    if(y * z < 0) break;
  }

  while(y < 1e-6){
    x+=1e-6;
    y = func(x);
  }

  printf("%.6lf", x);
  
  return 0;
}