#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using OVEC = vector<char>;
using TVEC = vector<vector<char>>;
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

using P = pair<int, int>;
#define MAX_H 510
#define MAX_W 510
int n, m, sx, sy, gx, gy;
char field[MAX_H][MAX_W];
int dist[MAX_H][MAX_W];
/* dx, dyの組み合わせで方向を指定{東, 北, 西, 南}の順 */
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

/* BFSで最短距離を求める */
// 辿り着けない場合IINF
int bfs(int sy, int sx, int gy, int gx) {  
  int h = n, w = m;
  queue<P> que;

  /* 最短距離配列の初期化 */
  REP(y, h) REP(x, w) { dist[y][x] = IINF; }

  que.push(P(sy, sx));  // スタート地点を格納
  dist[sy][sx] = 0;     // スタート地点の距離を0にする

  /* キューが空になるまでループ */
  while (que.size()) {
    P p = que.front();
    que.pop();
    if (p.first == gy && p.second == gx) break;

    // 4方向を探索
    REP(dir, 4) {
      // 探索中の座標をny, nxに代入
      int ny = p.first + dy[dir];
      int nx = p.second + dx[dir];

      if (0 > nx || nx >= w || 0 > ny || ny >= h) continue;  //範囲外判定
      if (field[ny][nx] == '#') continue;                    //壁判定
      if (dist[ny][nx] != IINF) continue;                    //到達判定(IINFでなければ到達済み)

      /* 移動可能であれば */
      que.push(P(ny, nx)); // 移動可能座標をqueにpush
      dist[ny][nx] = dist[p.first][p.second] + 1; // その地点の距離をpからの距離+1で確定
    }
  }
  return dist[gy][gx]; // ゴール地点との距離を返す
}

int main() {
  cin >> n >> m;
  REP(y, n) REP(x, m) { cin >> field[y][x]; }
  REP(y, n) {
    REP(x, m) {
      if(field[y][x] == 's') sy = y, sx = x;
      if(field[y][x] == 'g') gy = y, gx = x;
    }
  }

  int cnt = bfs(sx, sy, gy, gx);
  CO(cnt);
}