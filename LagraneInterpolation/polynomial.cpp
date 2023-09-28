#include <iostream>
#include <iomanip>

using namespace std;

double lagraneInterpolation(double xValue[], double yValue[], double x, size_t size) {
  double result = 0.0;
  for(int i = 0; i < size; i++) {
    double l = 1.0;
    for(int j = 0; j < size; j++) {
      if(j != i) {
        l *= (xValue[j] - x) / (xValue[j] - xValue[i]);
      }
    }
    result += l * yValue[i];
  }
  return result;
}

int main() {
  // x = 0, 20000, 40000, 60000, 80000
  // y = 9.81, 9.7487, 9.6879, 9.6879 9.5682
  double xValue[] = {0, 20000, 40000, 60000, 80000};
  double yValue[] = {9.81, 9.7487, 9.6879, 9.6879, 9.5682};
  double x = 42235;

  size_t size = sizeof(xValue) / sizeof(xValue[0]);

  double result = lagraneInterpolation(xValue, yValue, x, size);

  cout << fixed << setprecision(6) << result << endl;

  return 0;
}