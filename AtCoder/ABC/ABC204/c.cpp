#pragma region Template
#pragma region Includes
#include <bits/stdc++.h>
#include <unordered_set>
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
template<class T> using PQR = priority_queue<T, vector<T>, greater<T>>;
#define REP(i, m, n) for(int i = m; i < (int)(n); i++)
#define REPE(i, m, n) for(int i = m; i <= (int)(n); i++)
#define REPR(i, m, n) for(int i = m; i >= (int)(n); i--)
#define FORR(itr, dict) for(auto &itr : dict)
#define REPBIT(n) for(int bit = 0; bit < (1 << (int)(n)); bit++)
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
/* update 2021/02/17 */
////////////////////////////////////////////////////////////////////////////////////////////////////

LL ans = 0;

void dfs(int idx, VEC2<int> &G, VEC<int> &visited) {
  if(visited[idx] == 2) return;  // 探索済みならスルー
  
  ans++;
  visited[idx]++;  // 到達済み、探索未完了

  REP(i, 0, G[idx].size()) {
    int next = G[idx][i];
    if(visited[next] == 2) continue;  // 隣接頂点が探索済みならスルー

    if(visited[next] == 0) {  // 隣接頂点が未到達なら
      dfs(next, G, visited);  // 未到達の隣接頂点を探索
    }
  }

  visited[idx] = 2;  // 探索完了
}

void solve() {
  int n, m;  // n: 頂点数
  cin >> n >> m;
  if(m == 0) {
    CO(n);
    return;
  }

  VEC2<int> G(n);
  int u, v;
  REP(i, 0, m) {  // グラフ入力
    cin >> u >> v;
    u--;
    v--;
    G[u].emplace_back(v);
  }

  REP(i, 0, n) {
    VEC<int> visited(n, 0);  // visited: 0: 未到達, 1: 到達済み, 探索未完了, 2: 探索完了
    dfs(i, G, visited);      // 始点(根?)が複数存在する可能性も有り
  }

  CO(ans);
}

int main() {
  FAST;
  solve();
}