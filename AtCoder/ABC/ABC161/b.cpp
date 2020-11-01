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
  vector<int> A(N);
  int sum = 0;
  REP(i, N) {
    cin >> A[i];
    sum += A[i];
  }

  int cnt = 0;
  REP(i, N) {
    /*移行しないと整数除算でバグが出る可能性*/
    // if(A[i] >= sum / (4 * M)) {
    //   cnt++;
    // }
    /*移行後の式*/
    if(sum <= A[i] * 4 * M) {
      cnt++;
    }
  }
  if(cnt >= M) CO("Yes");
  else CO("No");
}