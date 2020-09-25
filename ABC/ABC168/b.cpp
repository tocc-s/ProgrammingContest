#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()

int main() {
  int K;
  cin >> K;
  string S;
  cin >> S;
  int s_len = S.length();
  vector<char> ans(K);

  REP(i, K) ans[i] = S[i];

  if (s_len > K) {
    REP(i, K) cout << ans[i];
    cout << "..." << endl;
  } else {
    REP(i, K) cout << ans[i];
    cout << endl;
  }
}