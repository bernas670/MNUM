#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double f(double x) { return x - 2 * log(x) - 5; }
double diff_f(double const x) { return 1 - 2 / x; }

void newton(double guess) {

  unsigned int counter = 0;
  double xn = guess;

  do {
    counter++;
    guess = xn;

    xn = guess - f(guess) / diff_f(guess);

  } while ( abs(xn - guess) > ERROR);

  cout << "Root : " << xn << endl;
  cout << "Number of Iterations : " << counter << endl;
}

int main() {

  newton(0.01);
  newton(10);

  return 0;
}
