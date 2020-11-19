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

int cnt = 0;

void dfs(int idx, VEC2<int> &G, VEC<int> &d, VEC<int> &f, VEC<int> &visited) {
  if(visited[idx] == 2) return;
  visited[idx]++;  // 到達済み、探索未完了
  cnt++;
  d[idx] = cnt;  // 到達時刻を代入

  REP(i, G[idx].size()) {
    if(visited[G[idx][i]] == 2) continue;  // 隣接頂点が探索済みならスキップ

    if(visited[G[idx][i]] == 0) {        // 隣接頂点が未到達なら
      dfs(G[idx][i], G, d, f, visited);  // 未到達の隣接頂点を探索
    }
  }

  visited[idx] = 2;  // 探索完了
  cnt++;
  f[idx] = cnt;  // 探索完了時刻を代入
}

void solve() {
  int n;  // n: 頂点数
  cin >> n;
  VEC2<int> G(n);
  VEC<int> d(n), f(n), visited(n, 0);  // visited: 0: 未到達, 1: 到達済み,探索未完了, 2: 探索完了
  int u, k, v;
  REP(i, n) {  // グラフ入力
    cin >> u >> k;
    u--;
    REP(j, k) {
      cin >> v;
      v--;
      G[u].emplace_back(v);
    }
  }

  REP(i, n) dfs(i, G, d, f, visited);  // 根が複数存在する可能性も有り

  REP(i, n) cout << i + 1 << " " << d[i] << " " << f[i] << en;
}

int main() {
  FAST;
  solve();
}