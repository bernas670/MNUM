#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) { return pow(x,2) + pow(y,2); }

double euler(double x0, double xf, double y0, double h) {

  double xn = x0, yn = y0;

  do {

    x0 = xn;
    y0 = yn;

    xn = x0 + h;
    yn = y0 + h * f(x0, y0);

    cout << "xn : " << xn << " yn : " << yn << endl;

  } while ( xn < xf );

  return yn;
}

int main() {

  cout << euler(0, 1.4, 0, 0.1) << endl;

  cout << euler(0, 1.4, 0, 0.05) << endl;

  cout << euler(0, 1.4, 0, 0.025) << endl;

  return 0;
}
