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
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  int N, K, d, cnt = 0;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N) A[i] = 0;

  REP(i, K) {
    cin >> d;
    REP(j, d) {
      int B;
      cin >> B;
      A[B-1]++;
    }
  }
  REP(i, N) if(A[i] == 0) cnt++;

  CO(cnt);
}