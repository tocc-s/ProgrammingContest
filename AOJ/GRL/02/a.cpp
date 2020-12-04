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

/* UnionFind */
class UnionFind {
 public:
  vector<int> par;
  vector<int> size;  // 木の要素数

  /* n 要素で初期化 */
  UnionFind() {}
  UnionFind(int n) {
    par.resize(n, 0);
    size.resize(n, 0);
    for(int i = 0; i < n; i++) {
      par[i] = i;
      size[i] = 1;  // 自分を含めた木のサイズ(要素数)
    }
  }

  /* 木の根を求める */
  int find(int x) {
    if(par[x] == x) return x;
    else
      return par[x] = find(par[x]);  // 経路圧縮
  }

  /* x と y の属する根(集合)を併合 */
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;  // 根が既に同じ

    /* 木のサイズ(size)(要素数)による併合 */
    if(size[x] > size[y]) swap(x, y);
    par[x] = y;
    size[y] += size[x];

    return true;
  }

  /* x と y が同じ集合に属するか判定 */
  bool same(int x, int y) { return find(x) == find(y); }

  /* 木のサイズを測定 */
  int treeSize(int x) { return size[find(x)]; }
};

struct Edge {
  int from, to, cost;
};

bool cost_comp(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

/* クラスカル法 (UnionFind 継承) */
class Kruskal {
 public:
  int n = 0, e = 0;
  VEC<Edge> edge;
  UnionFind uf;

  Kruskal() {}
  Kruskal(int num) : uf(num) {}

  /* 有向辺作成 */
  void directed_edge(int from, int to, int cost) {
    edge.emplace_back(Edge{from, to, cost});
    e++;
  }

  int cost_sum() {
    sort(ALL(edge), cost_comp);  // cost の小さい順に sort

    int sum = 0;
    for(int i = 0; i < e; i++) {
      Edge eg = edge[i];
      if(!uf.same(eg.from, eg.to)) {
        uf.unite(eg.from, eg.to);
        sum += eg.cost;
      }
    }
    return sum;
  }
};

template<class T> void debug(T KR) {
  VEC<Edge> edge = KR.edge;

  /* debug */
  CO();
  REP(i, 0, edge.size()) {
    cout << "from: " << edge[i].from << " | to: " << edge[i].to << " | cost: " << edge[i].cost;
    CO();
  }
}

void solve() {
  int v, e;
  cin >> v >> e;
  Kruskal KR(v);

  int s, t, d;
  REP(i, 0, e) {
    cin >> s >> t >> d;
    KR.directed_edge(s, t, d);
  }

  CO(KR.cost_sum());

  // debug(KR);
}

int main() {
  FAST;
  solve();
}