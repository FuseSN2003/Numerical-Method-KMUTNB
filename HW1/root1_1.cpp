#include <iostream>
#include <iomanip>

using namespace std;

double func(double x) {
  return (43 * x) - 180;
}

int main() {
  const double epsilon = 1e-6;
  double x = 0.0;
  double y, z;

  while(x <= 10) {
    y = func(x);
    z = func(x+1);

    if(y * z < 0) {
      break;
    }
    x++;
  }

  while(y < epsilon){
    y = func(x);
    x+=epsilon;
  }

  cout << fixed << setprecision(6) << x << endl;
  
  return 0;
}