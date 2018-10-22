#include <iostream>
#include <cmath>

using namespace std;

double const ERROR = pow(10, -5);

double f1(double x, double y) { return 2 * pow(x, 2) - x * y - 5 * x + 1; }
double diff_f1_x(double x, double y) { return -y + 4 * x - 5; }
double diff_f1_y(double x, double y) { return -x; }

double f2(double x, double y) { return x + 3 * log(x) - pow(y, 2); }
double diff_f2_x(double x, double y) { return 3 / x + 1; }
double diff_f2_y(double x, double y) { return -2 * y; }


void newton(double x_guess, double y_guess) {

  double xn = x_guess;
  double yn = y_guess;
  unsigned int counter = 0;

  do
  {
    x_guess = xn;
    y_guess = yn;

    xn = x_guess - (f1(x_guess, y_guess) * diff_f2_y(x_guess, y_guess) - f2(x_guess, y_guess) * diff_f1_y(x_guess, y_guess)) / (diff_f1_x(x_guess, y_guess) * diff_f2_y(x_guess, y_guess) - diff_f2_x(x_guess, y_guess) * diff_f1_y(x_guess, y_guess));
    yn = y_guess - (f2(x_guess, y_guess) * diff_f1_x(x_guess, y_guess) - f1(x_guess, y_guess) * diff_f2_x(x_guess, y_guess)) / (diff_f1_x(x_guess, y_guess) * diff_f2_y(x_guess, y_guess) - diff_f2_x(x_guess, y_guess) * diff_f1_y(x_guess, y_guess));

    counter++;
  } while ( abs(xn - x_guess) > ERROR && abs(yn - y_guess) > ERROR );

  cout << "( x , y ) = ( " << xn << " , " << yn << " ) " << endl;
  cout << "Number of Iterations : " << counter << endl;
}

int main() {

  newton(4, 4);

  return 0;
}
