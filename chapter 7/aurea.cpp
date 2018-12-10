#include <iostream>
#include <cmath>

using namespace std;

const double ERROR = pow(10, -3);

const double AUREA = (sqrt(5.0) - 1.0) / 2.0;
const double A = pow(AUREA, 2);
const double B = AUREA;

double f(double x) { return pow(2 * x + 1, 2) - 5 * cos(10 * x); }

double aurea_min(double x1, double x2) {
  double x3, x4;

  do {
    x3 = x1 + A * (x2 - x1);
    x4 = x1 + B * (x2 - x1);

    if ( f(x3) < f(x4) )
      x2 = x4;
    else if ( f(x3) > f(x4) )
      x1 = x3;

  } while ( abs(x1 - x2) > ERROR );

  if ( f(x1) < f(x2) ) {
    cout << "Minimum : ( " << x1 << " , " << f(x1) << " ) ." << endl;
    return f(x1);
  }
  else {
    cout << "Minimum : ( " << x2 << " , " << f(x2) << " ) ." << endl;
    return f(x2);
  }
}

double aurea_max(double x1, double x2) {
  double x3, x4;

  do {
    x3 = x1 + A * (x2 - x1);
    x4 = x1 + B * (x2 - x1);

    if ( f(x3) > f(x4) )
      x2 = x4;
    else if ( f(x3) < f(x4) )
      x1 = x3;

  } while ( abs(x1 - x2) > ERROR );

  if ( f(x1) > f(x2) ) {
    cout << "Maximum : ( " << x1 << " , " << f(x1) << " ) ." << endl;
    return f(x1);
  }
  else {
    cout << "Maximum : ( " << x2 << " , " << f(x2) << " ) ." << endl;
    return f(x2);
  }
}


int main() {

  double min, max;

  min = aurea_min(-1, 0);
  max = aurea_max(-1, 0);

  return 0;
}
