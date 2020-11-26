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

/* Lake Counting問題 */
int n, m;
VEC2<char> field(101, VEC<char>(101));

void dfs(int x, int y) {
  //現在の座標を以下の判定(field[nx][ny] == 'W')に引っかからないように'.'に置き換える
  field[x][y] = '.';

  /* 周囲8方向に'W'が存在するか調べる */
  REPE(dx, -1, 1) {
    REPE(dy, -1, 1) {
      // nx、ny: 探索箇所の座標
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
  REP(i, 0, n) {
    REP(j, 0, m) { cin >> field[i][j]; }
  }
  int cnt = 0;

  REP(i, 0, n) {
    REP(j, 0, m) {
      //現在の座標に水が存在する場合
      if(field[i][j] == 'W') {
        dfs(i, j);
        cnt++;
      }
    }
  }
  CO(cnt);
}