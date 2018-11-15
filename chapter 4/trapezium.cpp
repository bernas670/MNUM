#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1);

double f(double x) { return sin(x); }

void trapezium(double lBound, double hBound, unsigned int intervals) {

  double h = (hBound - lBound) / intervals;
  double sum = f(lBound) + f(hBound);

  for (unsigned int i = 1; i < intervals; i++) {
    sum += 2 * f(lBound + h * i);
  }

  sum = (h / 2) * sum;

  cout << "Area : " << sum  << " , " << intervals << endl;
}

int main() {

  trapezium(0, PI, 10);
  trapezium(0, PI, 20);
  trapezium(0, PI, 40);

  cout << endl;

  trapezium(PI/2, PI, 10);
  trapezium(PI/2, PI, 100);
  trapezium(PI/2, PI, 1000);

  return 0;
}
