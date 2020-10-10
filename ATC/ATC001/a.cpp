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

#define MAX_H 510
#define MAX_W 510
int h, w, gx, gy;
char field[MAX_H][MAX_W];
bool checked[MAX_H][MAX_W];
/* dx, dyの組み合わせで方向を指定{東, 北, 西, 南}の順 */
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

/* DFSで到達した座標をcheched[nx][ny]に入れる(true) */
void dfs(int y, int x) {
  checked[y][x] = true;

  /* 4方向探索 */
  REP(dir, 4) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (0 > nx || nx >= w || 0 > ny || ny >= h) continue;  //範囲外判定
    if (field[ny][nx] == '#') continue;                    //壁判定
    if (checked[ny][nx]) continue;                         //到達判定

    //範囲内、未到達、壁でもないなら再帰的に探索
    dfs(ny, nx);
  }
}

int main() {
  cin >> h >> w;
  REP(y, h) {
    REP(x, w) {  //入力と初期化
      cin >> field[y][x];
      checked[y][x] = false;
    }
  }

  REP(y, h) {
    REP(x, w) {
      if (field[y][x] == 's') dfs(y, x);  //スタート地点から探索開始
      if (field[y][x] == 'g') gy = y, gx = x;  //ゴール地点の座標を取得
    }
  }

  //探索した後でゴール地点に到達しているなら
  if (checked[gy][gx])
    CO("Yes");
  else
    CO("No");
}