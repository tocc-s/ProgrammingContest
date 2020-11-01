#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, r; 
  double a, b, f;
  cin >> a >> b;
  d = (int)a/(int)b;
  r = (int)a%(int)b;
  f = a/b;

  cout << d << " " << r << " " << fixed << setprecision(5) << f << endl;
}