#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void gauss_elimination(const unsigned int n_columns, const unsigned int n_lines) {

    int matrix[n_lines][n_columns];
    int independent_terms[n_lines];
    int element;


    for (unsigned int j = 0; j < n_lines; j++) {
      unsigned int i = 0;
      do {
        cin >> element;
        if (i == n_columns)
          independent_terms[j] = element;
        else
          matrix[j][i] = element;
          i++;
        } while(i <= n_columns);
    }

}



int main() {

  gauss_elimination(3,3);

  return 0;
}
