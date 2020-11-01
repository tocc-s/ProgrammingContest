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
  // cout << fixed << setprecision(15);
  string s;
  cin >> s;
  int n = s.size(), nfront = (n - 1) / 2;
  vector<char> s_tmp(n), s_tmp2(nfront);

  REP(i, n) { s_tmp[n - 1 - i] = s[i]; }
  REP(i, nfront) { s_tmp2[nfront - 1 - i] = s[i]; }

  bool flag1 = true, flag2 = true;
  REP(i, n) {
    if (s[i] != s_tmp[i]) flag1 = false;
  }
  REP(i, nfront) {
    if (s[i] != s_tmp2[i]) flag2 = false;
  }

  if (flag1 && flag2)
    CO("Yes");
  else
    CO("No");
}