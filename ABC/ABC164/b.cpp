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
  int A, B, C, D, div = 0;
  cin >> A >> B >> C >> D;

  while(1) {
    if(div % 2 == 0) {
      C -= B;
    } else {
      A -= D;
    }
    if(C <= 0) {
      CO("Yes");
      return 0;
    }
    if(A <= 0) {
      CO("No");
      return 0;
    }
    div++;
  }
  
}