#pragma region Region
#pragma region Fasts
#pragma GCC optimize("Ofast")
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#pragma endregion
#pragma region Includes
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#pragma endregion
#pragma region Defines
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
#define FORR(itr, dict) for (auto& itr : dict)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
constexpr int MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
template <class T>
void CO(T value) {
  cout << value << "\n";
}
#pragma endregion
#pragma endregion Region
///////////////////////////////////////////////////////////////////////////////

int main() {
  FAST;
  int n;
  cin >> n;
  unordered_set<string> p{};
  VEC<string> tmp(n);
  REP(i, n) cin >> tmp[i];

  char cc;
  REP(i, n) {
    int pl = p.size();

    if (i % 2 == 0) {  // 高橋くん
      // CO(i);
      p.insert(tmp[i]);
      if (p.size() == pl) {  // 同一単語
        CO("LOSE");
        return 0;
      }
      if (i != 0 && cc != tmp[i][0]) {  // しりとりになっていない
        CO("LOSE");
        return 0;
      }
    } else {  // 高橋クン
      // CO(i);
      p.insert(tmp[i]);
      if (p.size() == pl) {  // 同一単語
        CO("WIN");
        return 0;
      }
      if (cc != tmp[i][0]) {  // しりとりになっていない
        CO("WIN");
        return 0;
      }
    }

    cc = tmp[i][tmp[i].size() - 1];
    // CO(tmp[i][tmp[i].size() - 1]);
  }

  CO("DRAW");
}