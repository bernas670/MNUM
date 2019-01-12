#include <iostream>
#include <cmath>

using namespace std;

double fz(double x, double y, double z) { return z*x + y; }
double fy(double x, double y, double z) { return z*y + x; }

void runge_kutta(double x0, double y0, double z0, double h, double xf) {

  double xn = x0, yn = y0, zn = z0;
  unsigned int counter = 0;

  do {

    x0 = xn;
    y0 = yn;
    z0 = zn;

    xn = x0 + h;
    yn = y0 + h * fy( x0 + h / 2.0, y0 + h * fy(x0, y0, z0) / 2.0, z0 + h * fz(x0, y0, z0) / 2.0 );
    zn = z0 + h * fz( x0 + h / 2.0, y0 + h * fy(x0, y0, z0) / 2.0, z0 + h * fz(x0, y0, z0) / 2.0 );

    cout << "xn : " << xn << " yn : " << yn << " zn :" << zn << " cnt : " << counter << endl;

  } while( xn < xf );

  cout << endl << "xn : " << xn << " yn : " << yn << " zn :" << zn << " cnt : " << counter << endl;

}

int main() {

  runge_kutta(0, 1, 1, 0.1, 0.5);

  return 0;
}
