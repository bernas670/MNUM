#include <iostream>
#include <cmath>

using namespace std;

const double ERROR = pow(10, -3);

/*
// only able to calculate minimum of this function
// values : x0 = 1, y0 = 1, h = 1
double f(double x, double y) { return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12; }
double dfx(double x, double y) { return -2 * y + 4 * x; }
double dfy(double x, double y) { return 2 * y - 2 * x - 6; }
*/

// only able to calculate maximum of this function
// values : x0 = -1, y0 = 1, h = 1
double f(double x, double y) { return 2 * x * y + 2 * x - pow(x, 2) - 2 * pow(y, 2); }
double dfx(double x, double y) { return 2 * y + 2 - 2 * x; }
double dfy(double x, double y) { return 2 * x - 4 * y; }

/* multi-dimensional search */
double gradient_min(double x0, double y0, double h) {
  double xn = x0, yn = y0;

  do {
    x0 = xn;
    y0 = yn;

    xn = x0 - h * dfx(x0, y0);
    yn = y0 - h * dfy(x0, y0);

    if ( f(xn, yn) < f(x0, y0) ) {
      h *= 2.0;
    }
    else if ( f(xn, yn) > f(x0, y0) ) {
      h /= 2.0;
    }
  //  cout << xn << " " << yn << endl;
  } while ( abs(xn - x0) > ERROR && abs(yn - y0) > ERROR );

  //cout << "Minimum : " << f(x0, y0) << " on the point ( " << x0 << " , " << y0 << " ) ." << endl;
  cout << "Minimum : " << f(xn, yn) << " on the point ( " << xn << " , " << yn << " ) ." << endl;
  return f(xn, yn);
}

double gradient_max(double x0, double y0, double h) {
  double xn = x0, yn = y0;

  do {
    x0 = xn;
    y0 = yn;

    xn = x0 + h * dfx(x0, y0);
    yn = y0 + h * dfy(x0, y0);

    if ( f(xn, yn) > f(x0, y0) ) {
      h *= 2.0;
    }
    else if ( f(xn, yn) < f(x0, y0) ) {
      h /= 2.0;
    }
  //  cout << xn << " " << yn << endl;
  } while ( abs(xn - x0) > ERROR && abs(yn - y0) > ERROR );

  //cout << "Minimum : " << f(x0, y0) << " on the point ( " << x0 << " , " << y0 << " ) ." << endl;
  cout << "Maximum : " << f(xn, yn) << " on the point ( " << xn << " , " << yn << " ) ." << endl;
  return f(xn, yn);
}

int main() {

  gradient_min(-1, 1, 1);
  gradient_max(-1, 1, 1);

}
