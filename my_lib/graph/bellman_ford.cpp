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

/* ベルマンフォード法 */
class Bellman_Ford {
 private:
  struct Edge {  // 辺情報
    int from, to, cost;
  };
  VEC<Edge> edge;
  int n = 0, e = 0;  // 頂点数, 辺数

 public:
  VEC<int> dist;  // 距離
  VEC<int> prev;  // 経路保持
  Bellman_Ford(int point_num) {
    n = point_num;
    dist.resize(n, IINF);
    prev.resize(n, -1);
  }

  /* 有向辺作成 */
  void directed_edge(int from, int to, int cost) {
    edge.emplace_back(Edge{from, to, cost});
    e++;
  }

  /* 最短経路探索 */
  bool shortest_path(int start) {
    dist[start] = 0;
    int loop = 0;
    bool update = true;

    while(update) {  // 距離更新がある間ループ (高々 「頂点数-1」回)
      loop++;  // 「頂点数-1」(始点を含めない頂点数) に達すれば負閉路有り(無限ループ回避)
      update = false;
      for(int i = 0; i < e; i++) {
        Edge eg = edge[i];  // 探索中の辺

        /* 最短距離の更新が可能な場合 */
        if(dist[eg.from] != IINF && dist[eg.to] > dist[eg.from] + eg.cost) {
          dist[eg.to] = dist[eg.from] + eg.cost;  // 行先の頂点に、今までと探索中の辺のコストを格納
          prev[eg.to] = eg.from;          // 直前の頂点(最短経路)保持
          if(loop == n - 1) return true;  // 負閉路検出
          update = true;                  // 距離更新を行ったのでフラグを立てる
        }
      }
    }
    return false;  // 負閉路無し
  }

  /* 経路復元 */
  VEC<int> get_path(int goal) {
    VEC<int> path;
    for(int point = goal; point != -1; point = prev[point]) {
      path.emplace_back(point);
    }
    reverse(ALL(path));
    return path;
  }
};

void solve() {
  int v, e, r;
  cin >> v >> e >> r;
  Bellman_Ford G(v);
  VEC<int> path;

  int s, t, d;
  REP(i, 0, e) {
    cin >> s >> t >> d;
    G.directed_edge(s, t, d);
  }

  /* 最短距離探索 */
  if(G.shortest_path(r)) {
    CO("NEGATIVE CYCLE");
    return;
  } else {
    REP(i, 0, v) {
      if(G.dist[i] == IINF) CO("INF");
      else
        CO(G.dist[i]);
    }
  }

  /* 経路復元 */
  path = G.get_path(v - 1);
  cout << "---shortest Path---" << en;
  REP(i, 0, path.size()) {
    CON(path[i]);
    if(i != path.size() - 1) CON(" -> ");
  }
  CO();
}

int main() {
  FAST;
  solve();
}