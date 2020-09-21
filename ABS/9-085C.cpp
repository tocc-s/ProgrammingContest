#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
  int N, Y;
  cin >> N >> Y;

  rep(x, N) {
    rep(y, N-x) {
      int z = N-(x+y);
      if(x+y+z!=N) continue;
      if (Y == ((10000 * x) + (5000 * y) + (1000 * z))) {
        cout << x << " " << y << " " << z << '\n';
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << '\n';
}