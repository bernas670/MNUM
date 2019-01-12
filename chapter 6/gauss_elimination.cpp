#include <iostream>
#include <cmath>
#include <vector>


using namespace std;


void print(double **A, size_t rows, size_t cols ) {

  for (size_t i = 0; i < rows ; i++) {
    for (size_t j = 0; j < cols; j++) {
      cout << A[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

double* gauss(double **A, size_t rows, size_t cols, double x[]) {

    for (int i=0; i<rows; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<rows; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<cols;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<rows; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<cols; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A

    for (int i=rows-1; i>=0; i--) {
        x[i] = A[i][rows]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][rows] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main() {

    int n;
    cout << "Number of lines : ";
    cin >> n;

    double matrix[n][n+1];

    cout << endl;

    // Read input data
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        cin >> matrix[i][n];
    }

    // Print input
    double *b[n];  // surrogate
    for (size_t i = 0; i < 5; ++i)
    {
        b[i] = matrix[i];
    }
    print(b, n, n+1);


    // Calculate solution
    double x[n];
    gauss(b, n, n+1, x);

    // Print result
    cout << "Result:\t";
    for (int i=0; i<n; i++) {
        cout << x[i] << " ";
    }

    cout << endl;
}
