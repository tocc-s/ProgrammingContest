#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using GRAPH = vector<vector<int>>;
using PQ = priority_queue<int>;
using RPQ = priority_queue<int, vector<int>, greater<int>>;
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define VEC(any) vector<any>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
template <class T>
void CO(T value) {
  cout << value << endl;
}
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
#pragma endregion

int main() {
  int n, m;
  cin >> n >> m;
  VEC(int) h(n);
  GRAPH field(n, VEC(int)(n));
  REP(i, n) cin >> h[i];
  REP(i, m) cin >> field[i][0] >> field[i][1];  // Am[i], Bm[i]

  VEC(bool) good(n, false);
  REP(i, m) {
    if (h[field[i][0] - 1] > h[field[i][1] - 1]) {
      good[field[i][0] - 1] = true;
      good[field[i][1] - 1] = false;
    } else {
      good[field[i][0] - 1] = false;
      good[field[i][1] - 1] = true;
    }
  }

  int cnt = 0;
  REP(i, n) if(good[i] == true) cnt++;

  CO(cnt);
}