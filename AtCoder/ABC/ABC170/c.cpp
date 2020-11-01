#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
template <class T>
using P = pair<T, T>;
template <class T>
using VEC = vector<T>;
template <class T>
using GRAPH = vector<vector<T>>;
using PQ = priority_queue<int>;
using RPQ = priority_queue<int, vector<int>, greater<int>>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  int x, n;
  cin >> x >> n;
  if (n == 0) {
    CO(x);
    return 0;
  }
  set<int> p;
  REP(i, n) {
    int tmp;
    cin >> tmp;
    p.insert(tmp);
  }

  int index_sl, index_bg, diff = 0;
  while (1) {
    index_sl = x - diff;
    index_bg = x + diff;

    /* set p 内に、x から diff を引いた、または足した値が存在しなければ、
     * その値が、xとの差の絶対値の最小値なので出力
     */
    if (!p.count(index_sl)) {
      CO(index_sl);
      return 0;
    }
    if (!p.count(index_bg)) {
      CO(index_bg);
      return 0;
    }

    diff++;
  }
}