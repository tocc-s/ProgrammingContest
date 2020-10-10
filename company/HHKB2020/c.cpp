#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using OVEC = vector<int>;
using TVEC = vector<vector<int>>;
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  int n, nmin = 0, tmp = -1;
  cin >> n;
  vector<int> p(n);
  REP(i, n) cin >> p[i];

  REP(i, n) {
    tmp = max(p[i], tmp);
    if (nmin >= p[i] || nmin == tmp) {
      FOR(j, 0, i) {
        if (p[j] > nmin && p[j] < tmp)
          nmin = p[j];
        else
          nmin = tmp + 1;
      }
    }
    CO(nmin);
  }
}