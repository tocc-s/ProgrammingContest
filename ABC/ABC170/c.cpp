#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x, n, _min = 0, diff = 1;
  bool flag = false;
  cin >> x >> n;
  if (n == 0) {
    cout << x << '\n';
    return 0;
  }
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  sort(p.begin(), p.end());

  rep(i, n) {
    if (p[i] > x) break;
    if (p[i] != x) {
      _min = p[i];
    }
    // } else if (p[i] == x) {
    //   for (int j = 0; j < n; j++) {
    //     if (p[j] == p[i] - diff || p[j] == p[i] + diff) {
    //       diff++;
    //       continue;
    //     } else if (p[j] != p[i] - diff) {
    //       _min = p[i] - diff;
    //       break;
    //     } else if (p[i] + diff != p[j]) {
    //       _min = p[i] - diff;
    //       break;
    //     }
    //   }
    // }
  }
  cout << _min << '\n';
}