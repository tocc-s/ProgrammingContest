/* UnionFind */
class UnionFind {
 public:
  vector<int> par;
  // vector<int> rank; // 木の高さ
  // vector<int> size; // 木の要素数

  /* n 要素で初期化 */
  UnionFind() {}
  UnionFind(int n) {
    par.resize(n, 0);
    // rank.resize(n, 0);
    // size.resize(n, 0);
    for(int i = 0; i < n; i++) {
      par[i] = i;
      // rank[i] = 0; // 木の高さ(始めは 0)
      // size[i] = 1; // 自分を含めた木のサイズ(要素数)
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

    /* 基本 */
    if(par[x] > par[y]) swap(x, y);
    par[x] = y;

    /* 木の高さ(rank)による併合 */
    // if(rank[x] > rank[y]) swap(x, y);
    // par[x] = y;
    // if(rank[x] == rank[y]) rank[x]++;

    /* 木のサイズ(size)(要素数)による併合 */
    // if(size[x] > size[y]) swap(x, y);
    // par[x] = y;
    // size[y] += size[x];

    return true;
  }

  /* x と y が同じ集合に属するか判定 */
  bool same(int x, int y) { return find(x) == find(y); }

  /* 木のサイズを測定 */
  // int treeSize(int x) { return size[find(x)]; }
};