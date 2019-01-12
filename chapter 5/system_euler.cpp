#include <iostream>
#include <cmath>

using namespace std;

double fz(double x, double y, double z) { return z*x + y; }
double fy(double x, double y, double z) { return z*y + x; }

void euler(double x0, double y0, double z0, double hx, double xf) {

  unsigned int counter = 0;
  double xn = x0, yn = y0, zn = z0;
  double hy, hz;

  do {

    x0 = xn;
    y0 = yn;
    z0 = zn;

    hz = hx * fz(x0, y0, z0);
    hy = hx * fy(x0, y0, z0);

    xn = x0 + hx;
    yn = y0 + hy;
    zn = z0 + hz;

    counter++;

    cout << "xn : " << xn << " yn : " << yn << " zn : " << zn << " cnt : " << counter << endl;

  } while (xn < xf);

  cout << endl << "xn : " << xn << " yn : " << yn << " zn : " << zn << " cnt : " << counter << endl;
}

int main() {

  euler(0, 1, 1, 0.1, 0.5);

  return 0;
}
