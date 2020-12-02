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

/* ダイクストラ法 */
class Dijkstra {
 private:
  struct Edge {
    int next, cost;
  };
  VEC2<Edge> G;

 public:
  VEC<int> dist;  // 最短距離
  VEC<int> prev;  // 経路保持
  VEC<int> path;  // 最短経路
  Dijkstra(int n) {
    G.resize(n);
    dist.resize(n);
    prev.resize(n, -1);
  }

  /* 無向辺作成 */
  void undirected_edge(int now, int next, int cost) {
    G[now].emplace_back(Edge{next, cost});
    G[next].emplace_back(Edge{now, cost});
  }
  /* 有向辺作成 */
  void directed_edge(int now, int next, int cost) { G[now].emplace_back(Edge{next, cost}); }

  /* 最短経路探索 */
  void shortest_path(int start) {
    /* 最短距離の昇順で優先度キューを作成 */
    PQR<P<int>> que;  // pair.first: スタート地点からの最短距離 | pair.second: 頂点番号
    fill(ALL(dist), IINF);
    dist[start] = 0;
    que.push(make_pair(0, start));  // スタート地点を格納

    while(!que.empty()) {
      P<int> p = que.top();
      que.pop();
      int now = p.second;
      if(dist[now] < p.first) continue;  // 探索中の頂点の距離の方が遠ければスルー

      for(int i = 0; i < G[now].size(); i++) {  // 現地点との隣接頂点を調べる
        int next = G[now][i].next;              // 隣接頂点番号
        int cost = G[now][i].cost;              // 隣接頂点への辺の重み

        if(dist[next] > dist[now] + cost) {  // 隣接頂点が未探索の場合
          dist[next] = dist[now] + cost;  // 現地点までの重み、隣接頂点への重みを代入
          prev[next] = now;
          que.push(make_pair(dist[next], next));  // 隣接頂点を探索するための準備
        }
      }
    }
  }

  /* 経路復元 */
  VEC<int> get_path(int goal) {
    for(int point = goal; point != -1; point = prev[point]) {
      path.emplace_back(point);
    }
    reverse(ALL(path));
    return path;
  }

  /* 到達判定 */
  bool is_reach(int start) {
    REP(i, 0, path.size()) {
      if(path[i] == start) return true;
    }
    return false;
  }
};

void solve() {
  int v, e, r;
  cin >> v >> e >> r;
  Dijkstra G(v);
  VEC<int> path;

  int s, t, d;
  REP(i, 0, e) {
    cin >> s >> t >> d;
    G.directed_edge(s, t, d);  // 有向辺追加
  }

  G.shortest_path(r);  // 最短経路探索
  REP(i, 0, v) {
    if(G.dist[i] == IINF) CO("INF");
    else
      CO(G.dist[i]);
  }

  /* 経路復元 */
  path = G.get_path(v - 1);
  cout << "---shortest Path---" << en;
  if(G.is_reach(r)) {
    REP(i, 0, path.size()) {
      CON(path[i]);
      if(i != path.size() - 1) CON(" -> ");
    }
    CO();
  } else {
    CO("NOT EXIST");
  }
}

int main() {
  FAST;
  solve();
}