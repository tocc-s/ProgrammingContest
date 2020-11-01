#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, n, min = 1000001, max = -1000001;
  ll sum = 0;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a;
    if(a < min) min = a;
    if(a > max) max = a;
    sum += a;
  }
  cout << min << " " << max << " " << sum << endl;
}