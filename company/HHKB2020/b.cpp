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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];

  int cnt = 0;
  REP(i, h) {
    REP(j, w-1) {
      if(s[i][j] != '#' && s[i][j+1] != '#') cnt++;
    }
  }
  REP(i, h-1) {
    REP(j, w) {
      if(s[i][j] != '#' && s[i+1][j] != '#') cnt++;
    }
  }

  CO(cnt);
}