#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double f(double x) { return x - 2 * log(x) - 5; }

void rope(double lBound, double hBound) {

  double xn;
  unsigned int counter = 0;

  while ( abs(hBound - lBound) > ERROR )
  {
    counter++;

    xn = (lBound * f(hBound) - hBound * f(lBound)) / (f(hBound) - f(lBound));

    if ( f(lBound) * f(xn) < 0)
      hBound = xn;
    else
      lBound = xn;
  }

  cout << "Root : " << xn << endl;
  cout << "Number of Iterations : " << counter << endl;

}

int main() {

  rope(0.01, 1);
  rope(9, 10);

  return 0;
}
