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
template<class T> using PQR = priority_queue<T, vector<T>, greater<T>>;
#define REP(i, m, n) for(int i = m; i < (int)(n); i++)
#define REPE(i, m, n) for(int i = m; i <= (int)(n); i++)
#define REPR(i, m, n) for(int i = m; i >= (int)(n); i--)
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

class Warshall_Floyd {
 private:
  int n;

 public:
  VEC2<int> dist, prev;
  VEC<int> path;
  Warshall_Floyd(int point_num) {
    n = point_num;
    dist = VEC2<int>(n, VEC<int>(n, IINF));
    prev = VEC2<int>(n, VEC<int>(n));
    REP(i, 0, n) {
      REP(j, 0, n) { prev[i][j] = i; }
    }
  }

  /* 有向辺作成 */
  void directed_edge(int from, int to, int cost) { dist[from][to] = cost; }

  /* 最短経路探索 */
  bool shortest_path() {
    REP(start, 0, n) dist[start][start] = 0;  // 始点の距離は 0

    for(int pass = 0; pass < n; pass++) {                              // 経由頂点
      for(int start = 0; start < n; start++) {                         // 始点
        for(int goal = 0; goal < n; goal++) {                          // 終点
          if(dist[start][pass] == IINF || dist[pass][goal] == IINF) {  // 経路が存在しない
            continue;
          }
          /* 最短距離更新 */
          if(chmin(dist[start][goal], dist[start][pass] + dist[pass][goal])) {
            prev[start][goal] = prev[pass][goal];
          }
        }
        if(dist[start][start] < 0) return true;  // 負閉路検出
      }
    }
    return false;
  }

  /* 経路復元 */
  VEC<int> get_path(int start, int goal) {
    path.emplace_back(goal);
    for(int now = goal; now != start; now = prev[start][now]) {
      path.emplace_back(prev[start][now]);
    }
    reverse(ALL(path));
    return path;
  }

  bool is_reach(int start) {
    REP(i, 0, path.size()) {
      if(path[i] == start) {
        return true;
      }
    }
    return false;
  }
};

void solve() {
  int v, e;
  cin >> v >> e;
  Warshall_Floyd G(v);
  VEC<int> path;

  int s, t, d;
  REP(i, 0, e) {
    cin >> s >> t >> d;
    G.directed_edge(s, t, d);  // 有向辺追加
  }

  if(G.shortest_path()) {
    CO("NEGATIVE CYCLE");
    return;
  }
  REP(i, 0, v) {
    REP(j, 0, v) {
      if(G.dist[i][j] == IINF) CON("INF");
      else
        CON(G.dist[i][j]);
      if(j != v - 1) CON(" ");
    }
    CO();
  }

  /* 経路復元 */
  path = G.get_path(0, 2);
  cout << en << "---shortest Path---" << en;
  if(G.is_reach(0)) {  // 到達可能であれば(引数: スタート地点)
    REP(i, 0, path.size()) {
      CON(path[i]);
      if(i != path.size() - 1) CON(" -> ");
    }
    CO();
  } else {  // 到達不可能
    CO("NOT EXIST");
  }
}

int main() {
  FAST;
  solve();
}