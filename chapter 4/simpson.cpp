#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1);

double f(double x) { return sin(x); }

// NOTE : this method only works with an even number of intervals
void simpson(double lBound, double hBound, unsigned int intervals) {

  double h = (hBound - lBound) / (2 * intervals);
  double sum = f(lBound) + f(hBound);

  for (unsigned int i = 1; i < 2 * intervals - 1; i++) {
    if (i % 2 == 0)
      sum += 2 * f(lBound + h * i);
    else
      sum += 4 * f(lBound + h * i);
  }

  sum = (h / 3) * sum;

  cout << "Area : " << sum << endl;
}

int main() {

  simpson(0, PI, 10);
  simpson(0, PI, 100);
  simpson(0, PI, 1000);

  cout << endl;

  simpson(PI/2, PI, 10);
  simpson(PI/2, PI, 100);
  simpson(PI/2, PI, 1000);

  return 0;
}
