#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;
constexpr ll LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

/* ナップザック問題 DP */

void solve_dp02() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(W), value(n);
  int dp[110][10010];
  REP(i, n) cin >> weight[i] >> value[i];
  REPE(w, W) dp[0][w] = 0;

  REP(i, n) {
    REPE(w, W) {
      if (w >= weight[i])
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      else
        dp[i + 1][w] = dp[i][w];
    }
  }
  CO(dp[n][W]);
}

int main() {
  solve_dp02();
}