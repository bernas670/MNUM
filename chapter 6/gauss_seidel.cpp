#include <iostream>
#include <cmath>

using namespace std;

const double ERROR = pow(10, -5);

/* equation system used for this example
    3 * x1 + 1 * x2 + 1 * x3 = 7
    1 * x1 + 4 * x2 + 2 * x3 = 4
    0 * x1 + 2 * x2 + 5 * x3 = 5
*/

double fx1(double x2, double x3) { return (7-x2-x3)/3.0; }
double fx2(double x1, double x3) { return (4-x1-2*x3)/4.0; }
double fx3(double x1, double x2) { return (5-2*x2)/5.0; }

void gauss_seidel(double &x1, double &x2, double &x3, unsigned int &counter) {

  counter = 0;

  double x1k = x1, x2k = x2, x3k = x3;

  while (true) {
    x1 = x1k;
    x2 = x2k;
    x3 = x3k;

    x1k = fx1(x2, x3);
    x2k = fx2(x1k, x3);
    x3k = fx3(x1k, x2k);

    counter++;

    if ( abs(x1k - x1) < ERROR && abs(x2k - x2) < ERROR && abs(x3k - x3) < ERROR )
      break;
  }

  x1 = x1k;
  x2 = x2k;
  x3 = x3k;

}

int main() {

  unsigned int cnt = 0;
  double x1 = 0, x2 = 0, x3 = 0;

  gauss_seidel(x1, x2, x3, cnt);

  cout << "x1 : " << x1 << " " << " x2 : " << x2 << " x3 : " << x3 << endl;
  cout << "iterations : " << cnt << endl;

  return 0;
}
