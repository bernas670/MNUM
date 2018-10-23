#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, double y) { return log(2 * x) + 0.5 * x * pow(y, 2) - y; }

double simpson(vector<double> points, double h) {

  double evens = 0;
  double odds = 0;

  // process the odds
  for (unsigned int i = 1; i < points.size() - 1; i += 2)
    odds += points[i];

  // process the evens
  for (unsigned int i = 2; i < points.size() - 1; i += 2)
    evens += points[i];

  double integral = (h / 3) * ( 4 * odds + 2 * evens + points[0] + points[points.size() - 1]);

  return integral;
}

int main() {

  const double a = 2;
  const double A = 7;
  const double b = 1;
  const double B = 5;

  const unsigned int n = 1000;

  const double hx = (A - a) / n;
  const double hy = (B - b) / n;

  vector<double> averages;
  vector<double> row;

  for (unsigned int i = 0; i <= n; i++) {
    row.clear();


    for (unsigned int j = 0; j <= n; j++)
      row.push_back( f(a + hx * i, b + hy * j) );

    averages.push_back(simpson(row, hy));
  }

  double result = simpson(averages, hx);

  cout << result << endl;

  return 0;
}
