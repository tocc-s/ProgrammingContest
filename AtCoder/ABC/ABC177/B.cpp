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
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  string S, T;
  cin >> S >> T;

  int cnt = 0, m = 1001;
  for (int i = 0; i <= S.length() - T.length(); i++) {
    cnt = 0;
    for (int j = 0; j < T.length(); j++) {
      if (S[i + j] != T[j]) cnt++;
    }
    m = min(m, cnt);
  }
  CO(m);
}