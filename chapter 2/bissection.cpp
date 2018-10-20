#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double f(double x) { return x - 2 * log(x) - 5; }

void bissection(double lBound, double hBound) {

  double xn = 0;
  unsigned int counter = 0;

  while ( abs(hBound - lBound) > ERROR ) {

    counter++;

    xn = (lBound + hBound) / 2;

    if ( f(lBound) * f(xn) < 0 )
      hBound = xn;
    else
      lBound = xn;
  }

  cout << "Root value : " << xn << endl;
  cout << "Number of Iterations : " << counter << endl;
}

int main() {

  bissection(0, 1);
  bissection(9, 10);

  return 0;
}
