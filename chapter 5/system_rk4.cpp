#include <iostream>
#include <cmath>

using namespace std;

double fz(double x, double y, double z) { return z*x + y; }
double fy(double x, double y, double z) { return z*y + x; }

void runge_kutta(double x0, double y0, double z0, double hx, double xf) {

  unsigned int counter = 0;
  double xn = x0, yn = y0, zn = z0;
  double dy1, dy2, dy3, dy4;
  double dz1, dz2, dz3, dz4;

  do {

    x0 = xn;
    y0 = yn;
    z0 = zn;

    dy1 = hx * fy(x0, y0, z0);
    dz1 = hx * fz(x0, y0, z0);
    dy2 = hx * fy(x0 + hx / 2.0, y0 + dy1 / 2.0, z0 + dz1 / 2.0);
    dz2 = hx * fz(x0 + hx / 2.0, y0 + dy1 / 2.0, z0 + dz1 / 2.0);
    dy3 = hx * fy(x0 + hx / 2.0, y0 + dy2 / 2.0, z0 + dz2 / 2.0);
    dz3 = hx * fz(x0 + hx / 2.0, y0 + dy2 / 2.0, z0 + dz2 / 2.0);
    dy4 = hx * fy(x0 + hx, y0 + dy3, z0 + dz3);
    dz4 = hx * fz(x0 + hx, y0 + dy3, z0 + dz3);

    xn = x0 + hx;
    yn = y0 + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;
    zn = z0 + dz1 / 6.0 + dz2 / 3.0 + dz3 / 3.0 + dz4 / 6.0;

    counter++;

    cout << "xn : " << xn << " yn : " << yn << " zn : " << zn << " cnt : " << counter << endl;

  } while (xn < xf);

  cout << endl << "xn : " << xn << " yn : " << yn << " zn : " << zn << " cnt : " << counter << endl;
}

int main() {

  runge_kutta(0, 1, 1, 0.1, 0.5);

  return 0;
}
