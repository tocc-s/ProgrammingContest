#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  ll N, K, min;
  cin >> N >> K;
  if (N == 0 || K == 1 || N == K) {
    CO(0);
    return 0;
  }

  /*TLE*/
  // if (N > K) {
  //   while (N > K) {
  //     N -= K;
  //   }
  // }
  N = N % K;
  if (N == 0 || K == 1 || N == K) {
    CO(0);
    return 0;
  }
  min = N;
  N = abs(N - K);
  if (min < N) {
    CO(min);
  } else {
    CO(N);
  }
}