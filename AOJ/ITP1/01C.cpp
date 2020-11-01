#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, ans01 = 0, ans02 = 0; cin >> a >> b;
  ans01 = a * b;
  ans02 = a * 2 + b * 2;
  cout << ans01 << " " << ans02 << endl;
}