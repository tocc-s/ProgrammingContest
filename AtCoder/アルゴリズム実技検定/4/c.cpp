#pragma region Template
#pragma region Includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion Includes
#pragma region Setting
#pragma GCC optimize("Ofast")
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#pragma endregion Setting
#pragma region Defines
using LL = long long;
template<class T> using P = pair<T, T>;
template<class T> using VEC = vector<T>;
template<class T> using VEC2 = vector<vector<T>>;
template<class T> using PQ = priority_queue<T>;
template<class T> using RPQ = priority_queue<T, vector<T>, greater<T>>;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPE(i, n) for(int i = 0; i <= n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORE(i, m, n) for(int i = m; i <= n; i++)
#define FREV(i, m, n) for(int i = m; i >= n; i--)
#define FORR(itr, dict) for(auto &itr : dict)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
#define en '\n'
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr int MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
#pragma endregion Defines
#pragma region Functions
void string_lower(string &s, int n) {
  if(s[n] >= 65 && s[n] <= 90) s[n] = s[n] + ('a' - 'A');
}
void string_upper(string &s, int n) {
  if(s[n] >= 97 && s[n] <= 122) s[n] = s[n] - ('a' - 'A');
}
template<class T> inline void CO(T value) { cout << value << en; }
inline void CO(void) { cout << en; }
template<class T> inline void CON(T value) { cout << value; }
int ctoi(char c) {
  if('0' <= c && c <= '9') return (c - '0');
  else {
    CO("ctoi error!");
    return -1;
  }
}
char itoc(int n) { return n + '0'; }
template<class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool int_chk(T n) {
  if(ceil(n) == floor(n)) return true;
  return false;
}
#pragma endregion Functions
#pragma endregion Template
////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
  int n, m;
  cin >> n >> m;
  VEC<string> s(n);
  REP(i, n) cin >> s[i];

  VEC2<int> ans(n, VEC<int>(m, 0));
  REP(i, n) {
    REP(j, m) {
      if(s[i][j] == '#') ans[i][j]++;  // その場
      if(j > 0)
        if(s[i][j - 1] == '#') ans[i][j]++;  // 左
      if(j > 0 && i > 0)
        if(s[i - 1][j - 1] == '#') ans[i][j]++;  // 左上
      if(i > 0)
        if(s[i - 1][j] == '#') ans[i][j]++;  // 上
      if(i > 0 && j < m - 1)
        if(s[i - 1][j + 1] == '#') ans[i][j]++;  // 右上
      if(j < m - 1)
        if(s[i][j + 1] == '#') ans[i][j]++;  // 右
      if(i < n - 1 && j < m - 1)
        if(s[i + 1][j + 1] == '#') ans[i][j]++;  // 右下
      if(i < n - 1)
        if(s[i + 1][j] == '#') ans[i][j]++;  //　下
      if(i < n - 1 && j > 0)
        if(s[i + 1][j - 1] == '#') ans[i][j]++;  // 左下
    }
  }

  REP(i, n) {
    REP(j, m) { CON(ans[i][j]); }
    CO();
  }
}

int main() {
  FAST;
  solve();
}