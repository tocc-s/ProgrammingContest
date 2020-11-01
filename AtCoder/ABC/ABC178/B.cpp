#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll max;

  max = a * c;
  if(max < (a * d)) max = a * d;
  if(max < (b * c)) max = b * c;
  if(max < (b * d)) max = b * d;

  cout << max << endl;
}