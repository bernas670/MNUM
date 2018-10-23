#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) { return log(2 * x) + 0.5 * x * pow(y, 2) - y; }

void trapezium(double a, double A, double b, double B, unsigned int intervals) {

  double hx = (A - a) / intervals;
  double hy = (B - b) / intervals;

  double sum = f(a, b) + f(a, B) + f(A, b) + f(A, B);

  for (unsigned int i = 1; i < intervals; i++) {
    // sum of the intermidiate values
    sum += 2 * (f(a, b + hy * i) + f(A, b + hy * i));
    sum += 2 * (f(a + hx * i, b) + f(a + hx * i, B));

    // sum of the interior values
    for (unsigned int j = 1; j < intervals; j++)
      sum += 4 * f(a + hx * i, b + hy * j);
  }
  sum = ((hx * hy) / 4) * sum;

  cout << "Volume : " << sum << endl;
}

int main() {

  trapezium(2, 7, 1, 5, 1000);

  return 0;
}
