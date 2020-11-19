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

bool dfs(int idx, int c, VEC<int> &color, VEC2<int> &G) {
  color[idx] = c;
  REP(i, G[idx].size()) {
    if(color[G[idx][i]] == c) return false;  // 隣接頂点が同色なら false
    if(color[G[idx][i]] == 0 && !dfs(G[idx][i], -c, color, G))
      return false;  // 隣接頂点がまだ塗られていないなら -c で塗る
  }
  return true;  // 頂点 i について全て塗り終えられたら true
}

void solve() {
  int n, e;  // n: 頂点数, e: 張る辺の数
  cin >> n >> e;
  VEC2<int> G(n);
  VEC<int> color(n);  // 各頂点の色
  int from, to;
  REP(i, e) {  // グラフ入力
    cin >> from >> to;
    G[from].emplace_back(to);
    G[to].emplace_back(from);  // 無向グラフ
  }
  
  REP(i, n) {
    if(color[i] == 0) {
      if(!dfs(i, 1, color, G)) {
        CO("No");
        return;
      }
    }
  }
  CO("Yes");

  CO();
  REP(i, n) {
    cout << "point " << i << " to ";
    REP(j, G[i].size()) {
      CON(G[i][j]);
      if(j != G[i].size() - 1) CON(" & ");
    }
    cout << " / color: " << color[i] << en;
  }
}

int main() {
  FAST;
  solve();
}