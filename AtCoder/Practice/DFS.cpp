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

/* Lake Counting問題 */
int n, m;
TVEC field(101, OVEC(101));

void dfs(int x, int y) { 
  //現在の座標を以下の判定(field[nx][ny] == 'W')に引っかからないように'.'に置き換える
  field[x][y] = '.';

  /* 周囲8方向に'W'が存在するか調べる */
  FORE(dx, -1, 1) {
    FORE(dy, -1, 1) {
      //nx、ny: 探索箇所の座標
      int nx = x + dx, ny = y + dy;
      //もし範囲内かつ探索箇所が'W'であれば、再帰的に、見つかった場所からの8方向を探索
      if(0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W') dfs(nx, ny);
    }
  }
  //これ以上見つからなければ探索終了(cnt++)
  return;
}

int main() {  
  cin >> n >> m;
  REP(i, n) {
    REP(j, m) {
      cin >> field[i][j];
    }
  }
  int cnt = 0;

  REP(i, n) {
    REP(j, m) {
      //現在の座標に水が存在する場合
      if(field[i][j] == 'W') {
        dfs(i, j);
        cnt++;
      }
    }
  }
  CO(cnt);
}