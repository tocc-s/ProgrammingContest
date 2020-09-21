#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, T, ans = 0;
  cin >> N >> X >> T;

  while (N > 0) {
    ans += T;
    N = N - X;
  }

  cout << ans << endl;
}