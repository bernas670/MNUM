#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) { return pow(x,2) + pow(y,2); }

double runge_kunta(double x0, double xf, double y0, double h) {

  double xn = x0, yn = y0;
  double dy1, dy2, dy3, dy4;

  do {

    x0 = xn;
    y0 = yn;

    xn = x0 + h;

    dy1 = h * f(x0, y0);
    dy2 = h * f(x0 + h/2, y0 + dy1/2);
    dy3 = h * f(x0 + h/2, y0 + dy2/2);
    dy4 = h * f(x0 + h, y0 + dy3);

    //cout << dy1 << " " << dy2 << " " << dy3 << " " << dy4 << endl;

    yn = y0 + (dy1 + dy4)/6 + (dy2 + dy3)/3;

    cout << "xn : " << xn << " yn : " << yn << endl;

  } while(xn < xf);

return yn;
}

int main() {

  cout << runge_kunta(0, 1.4, 0, 0.1) << endl;
  cout << runge_kunta(0, 1.4, 0, 0.05) << endl;
  cout << runge_kunta(0, 1.4, 0, 0.025) << endl;

  return 0;
}
