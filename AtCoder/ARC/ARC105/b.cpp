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

// int nmax = -1, nmin = IINF;
// int maxmin(int n, vector<int> a) {
//   nmax = -1, nmax = IINF;
//   REP(i, n) {
//     nmax = max(nmax, a[i]);
//     nmin = min(nmin, a[i]);
//   }
//   if (nmax == nmin) {
//     return nmax;
//   } else {
//     REP(i, n) {
//       if (a[i] == nmax) {
//         a[i] = nmax - nmin;
//       }
//     }
//     return maxmin(n, a);
//   }
// }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  int nmax, nmin;
  while (1) {
    nmax = -1, nmin = IINF;
    REP(i, n) {
      nmax = max(nmax, a[i]);
      nmin = min(nmin, a[i]);
    }
    // CO(nmax);
    // CO(nmin);
    if (nmax == nmin) {
      break;
    }
    REP(i, n) {
      // cout << a[i] << " ";
      if (a[i] == nmax) {
        a[i] = nmax - nmin;
      }
    }
  }

  // int ans = maxmin(n, a);
  CO(nmax);
}