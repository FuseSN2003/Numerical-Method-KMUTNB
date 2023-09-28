#include <iostream>
#include <iomanip>

using namespace std;

double dividedDifference(double xValue[], double yValue[], int n) {
  if (n == 1) {
    return yValue[0];
  } else {
    return (dividedDifference(xValue + 1, yValue + 1, n - 1) - dividedDifference(xValue, yValue, n - 1)) / (xValue[n - 1] - xValue[0]);
  }
}

double interpolate(double xValue[], double yValue[], int n, double x) {
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    double term = dividedDifference(xValue, yValue, i + 1);
    for (int j = 0; j < i; j++) {
      term *= (x - xValue[j]);
    }
    result += term;
  }
  return result;
}

int main() {
  double xValue[] = {0, 20000, 40000, 60000, 80000};
  double yValue[] = {9.81, 9.7487, 9.6879, 9.6879, 9.5682};
  double x = 42235;
  int n = sizeof(xValue) / sizeof(xValue[0]);

  double result = interpolate(xValue, yValue, n, x);

  cout << fixed << setprecision(6) << result << endl;

  return 0;
}