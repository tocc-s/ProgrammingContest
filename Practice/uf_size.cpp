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

void solve() {
  int n, q;
  cin >> n >> q;
  int com, x, y;
  UnionFind tree = UnionFind(n);

  REP(i, 0, q) {
    cin >> com >> x >> y;

    /* unite */
    if(com == 0) tree.unite(x, y);
    /* same */
    else if(com == 1) {
      if(tree.same(x, y)) CO(1);
      else
        CO(0);
    }
  }

  CO();
  CO("size");
  REP(i, 0, n) { CO(tree.treeSize(i)); }
}

int main() {
  FAST;
  solve();
  /* Ex: input */
  /*
    5 5
    0 1 4
    1 1 2
    1 3 4
    0 2 3
    1 2 3
  */
}