#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr int IINF = 1e9;
constexpr ll LINF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) { cout << value << endl; }
#pragma endregion

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end());

  int sum = 0, ma = -1, mi = IINF;
  REP(i, N) {
    ma = max(ma, A[i]);
    mi = min(mi, A[i]);
    sum += A[i];
  }

  CO(sum);
}