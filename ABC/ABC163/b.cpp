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
void CO(T value) { cout << value << endl; }
#pragma endregion

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M) cin >> A[i];

  ll diff = -99, sum = 0;
  REP(i, M) {
    sum += A[i];
  }
  diff = N - sum;

  if(diff >= 0) CO(diff);
  else CO(-1);

}