#include <iostream>
#include <cmath>

using namespace std;

const double ERROR = pow(10, -3);

double f(double x, double y) { return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12; }
double dfx(double x, double y) { return -2 * y + 4 * x; }
double dfy(double x, double y) { return 2 * y - 2 * x - 6; }
// in this particular case H is a constant, but it might be an expression
double HM(double x, double y) { return 4.0; }

double quadric_min(double x0, double y0) {
  double xn = x0, yn = y0;

  do {
    x0 = xn;
    y0 = yn;

    xn = x0 - 1.0 / HM(x0, y0) * dfx(x0, y0);
    yn = y0 - 1.0 / HM(x0, y0) * dfy(x0, y0);
    cout << "xn = " << xn << "    " << "yn = " << yn << endl;

  } while ( abs(xn - x0) > ERROR && abs(yn - y0) > ERROR );

  if ( f(xn, yn) < f(x0, y0) )
    return f(xn, yn);
  else
    return f(x0, y0);
}

int main() {

  double min = quadric_min(-1, 1);
  cout << "min : " << min << endl;

  return 0;
}
