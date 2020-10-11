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
int h, w, sy, sx, gy, gx;
char field[MAX_H][MAX_W];
bool checked[MAX_H][MAX_W];
/* dx, dyの組み合わせで方向を指定{東, 北, 西, 南}の順 */
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

void bfs(int sy, int sx) {
  queue<P> que;
  que.push(P(sy, sx));
  checked[sy][sx] = true;

  while (que.size()) {
    P p = que.front();  // pへ、キューに格納されている先頭座標を代入
    que.pop();          // 代入したので先頭座標を削除    

    /* 4方向を探索 */
    REP(dir, 4) {
      // 探索する座標をny, nxに代入
      int ny = p.first + dy[dir];
      int nx = p.second + dx[dir];

      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;   // 範囲外なら次の方向へ
      if (field[ny][nx] == '#') continue;                     // 壁なら次の方向へ
      if (checked[ny][nx]) continue;                          // 到達済みなら次の方向へ

      /* 移動可能なら */      
      que.push(P(ny, nx)); // 移動した座標を、次の探索の為にキューに格納 
      checked[ny][nx] = true; // 移動して探索済みの状態にする     
    }
  }
}

int main() {  
  cin >> h >> w;
  REP(y, h) REP(x, w) {
    cin >> field[y][x];
    checked[y][x] = false;
  }

  REP(y, h) {
    REP(x, w) {
      if (field[y][x] == 's') sy = y, sx = x;  // スタート地点の座標を代入
      if (field[y][x] == 'g') gy = y, gx = x;  // ゴール地点の座標を代入
    }
  }

  bfs(sy, sx);  // 探索開始

  /* 到達判定 */
  if (checked[gy][gx])  // 到達済みなら"Yes"
    CO("Yes");
  else
    CO("No");
}