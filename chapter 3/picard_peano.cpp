#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double g1(double x, double y) { return sqrt((x*y + 5 * x - 1) / 2); }
double g2(double x, double y) { return sqrt(x + 3 * log(x)); }

void picard_peano(double x_guess, double y_guess) {

  double xn = x_guess;
  double yn = y_guess;
  unsigned int counter = 0;

  do {
    x_guess = xn;
    y_guess = yn;

    xn = g1(x_guess, y_guess);
    yn = g2(x_guess, y_guess);

    counter++;
  } while ( abs( xn - x_guess ) > ERROR && abs( yn - y_guess ) > ERROR );

  cout << "( x , y ) = ( " << xn << " , " << yn << " ) " << endl;
  cout << "Number of Iterations : " << counter << endl;
}

int main() {

  picard_peano(4, 4);

  return 0;
}
