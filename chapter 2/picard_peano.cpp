#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double g(double x) { return 2 * log(x) + 5; }
double diff_g(double const x) { return 2 / x; }

void picard_peano(double guess) {

  unsigned int counter = 0;
  double xn = guess;

  do {
    guess = xn;
    xn = g(guess);
    counter++;
  } while( abs(xn - guess) > ERROR);

  cout << "Root : " << xn << endl;
  cout << "Number of Iterations : " << counter << endl;
}

int main() {

  picard_peano(0.01); // not possible to calculate this root using this method
  picard_peano(9);

  return 0;
}
