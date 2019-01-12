#include <iostream>
#include <cmath>

using namespace std;

double ERROR = pow(10, -5);
double f(double x) { return pow(2 * x + 1, 2) - 5 * cos(10 * x); }

double thirds(double lBound, double hBound, const bool minimum) {

  double dx, x1, x2;
  unsigned int cnt = 0;

  do {

    dx = abs( hBound - lBound ) / 3.0;

    x1 = lBound + dx;
    x2 = hBound - dx;

    if ( minimum ) {
      if ( f(x1) < f(x2) )
        hBound = x2;
      else if ( f(x2) < f(x1) )
        lBound = x1;
    }
    else {
      if ( f(x1) > f(x2) )
        hBound = x2;
      else if ( f(x2) > f(x1) )
        lBound = x1;
    }

    cnt++;

  } while ( abs( f(lBound) - f(hBound) ) > ERROR );

  cout << "iterations : " << cnt << endl;

  if ( minimum ){
    if ( f(lBound) < f(hBound) )
      return f(lBound);
    else
      return f(hBound);
  }
  else {
    if ( f(lBound) > f(hBound) )
      return f(lBound);
    else
      return f(hBound);
  }
}


int main() {

  double min, max;

  min = thirds(-1, 0, true);
  cout << "min : " << min << endl;

  max = thirds(-1, 0, false);
  cout << "max : " << max << endl;

  return 0;
}
