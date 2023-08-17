#include <iostream>

double findDet(double matrix[3][3]) {
  double det = 0.0;
  for (int i = 0; i < 3; i++) {
    double term1 = 1.0, term2 = 1.0;

    for(int j = 0; j < 3; j++) {
      term1 *= matrix[(i + j) % 3][j];
      term2 *= matrix[(i - j + 3) % 3][j];
    }
    det += term1 - term2;
  }
  return det;
}

int main() {
  double matrix[3][3] = {{-2.0, 3.0, 1.0},{3.0, 4.0, -5.0}, {1.0, -2.0, 1.0}};
  double ans[3] = {9.0, 0.0, -4.0};

  double det = findDet(matrix);
  double solution[3];
  for(int i = 0; i < 3; i++) {
    double tempMatrix[3][3];
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        tempMatrix[j][k] = matrix[j][k];
      }
      tempMatrix[j][i] = ans[j];
    }
    solution[i] = findDet(tempMatrix) / det;
  }

  for(int i = 0; i < 3; i++) {
    std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
  }

  return 0;
}