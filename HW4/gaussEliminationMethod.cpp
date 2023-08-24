#include <iostream>
using namespace std;

#define ROWS 3

void gaussElimination(double matrix[ROWS][ROWS], double ans[ROWS]) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = i + 1; j < ROWS; j++) {
            double ratio = matrix[j][i] / matrix[i][i];

            for (int k = i; k < ROWS; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }

            ans[j] -= ratio * ans[i];
        }
    }

  // Back substitution
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = i + 1; j < ROWS; j++) {
        ans[i] -= matrix[i][j] * ans[j];
        }
        ans[i] /= matrix[i][i];
    }
}

int main() {
    double matrix[ROWS][ROWS] = {{-2.0, 3.0, 1.0}, {3.0, 4.0, -5.0}, {1.0, -2.0, 1.0}};
    double ans[ROWS] = {9.0, 0.0, -4.0};

    gaussElimination(matrix, ans);

    cout << "Solution:" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "x" << i << " = " << ans[i] << endl;
    }

    return 0;
}
