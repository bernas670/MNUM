#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
// EXERCISE 1
// ERROR = pow(10, -5)   x0 = y0 = 0   lambda = 0.5
double  f(double x, double y) { return pow(x + 1, 2) + pow(y - 4, 2); }
double gx(double x, double y) { return 2 * ( x + 1 ); }
double gy(double x, double y) { return 2 * ( y - 4 ); }
double  H(double x, double y) { return 4.0; }
*/

// EXERCISE 2
// ERROR = pow(10, -3)   x0 = y0 = 1   lambda = 0.1
double  f(double x, double y) { return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 15 + cos(10 * x); }
double gx(double x, double y) { return -2 * y - 10 * sin(10 * x) + 4 * x; }
double gy(double x, double y) { return 2 * y - 2 * x - 6; }
double  H(double x, double y) { return 2 * (4 - 100 * cos(10 * x)) - 4; }

void lavemberg_marquadt(double x0, double y0, double lambda, const double error) {

  double xn = x0, yn = y0, hx, hy;
  unsigned int counter = 0;

  do {
    x0 = xn;
    y0 = yn;

    hx = ( gx(x0, y0) / H(x0, y0) ) + ( lambda * gx(x0, y0) );
    hy = ( gy(x0, y0) / H(x0, y0) ) + ( lambda * gy(x0, y0) );

    xn = x0 - hx;
    yn = y0 - hy;

    if ( f(xn, yn) < f(x0, y0) ) {
      lambda /= 2;
    }
    else if ( f(xn, yn) > f(x0, y0) ) {
      lambda *= 2;
    }

    counter++;

    cout << setw(2) << counter << ". f( " << xn << " , " << yn << " ) = " << f(xn, yn) << endl;
  } while ( abs( xn - x0 ) > error &&  abs( yn - y0) > error );

}


int main() {

  lavemberg_marquadt(1, 1, 0.1, pow(10, -3));

  return 0;
}
