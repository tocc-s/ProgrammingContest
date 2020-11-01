#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, m, k, _max = 0, cnt = 0;
  ll sum = 0;
  cin >> n >> m >> k;
  _max = max(n, m);
  vector<int> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, _max) {
    if (i < n) {
      sum += a[i];
      if (sum <= k) cnt++;
    }
    if (i < m) {
      sum += b[i];
      if (sum <= k) cnt++;
    }
  }
  cout << cnt << '\n';
}