#pragma region includes
#include <bits/stdc++.h>
#pragma endregion
#pragma region defines
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T> void CO(T value) { cout << value << endl; }
#pragma endregion

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  ll cnt = 0;

  REP(i, K) {
    if (A > 0) {
      cnt++;
      A--;
      continue;
    } else if (B > 0) {
      B--;
      continue;
    } else if (C > 0) {
      cnt--;
      C--;
      continue;
    }
  }

  CO(cnt);
}