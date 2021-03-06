#pragma region Template
#pragma region Includes
#include <bits/stdc++.h>
#include <unordered_set>
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
#define REPBIT(n) for(int bit = 0; bit < (1 << (int)(n)); bit++)
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
/* update 2021/02/17 */
////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
  FAST;
  int n;
  cin >> n;
  /* v[i][0] = a[i], v[i][1] = b[i], v[i][2] = c[i] */
  VEC2<int> v(n, VEC<int>(3));
  VEC2<int> dp(n + 10, VEC<int>(3));
  REP(i, 0, n) REP(j, 0, 3) cin >> v[i][j];
  dp[0][0] = v[0][0];
  dp[0][1] = v[0][1];
  dp[0][2] = v[0][2];

  REP(i, 0, n) {
    REP(j, 0, 3) {    // j : 前日に選んだ活動の添字
      REP(k, 0, 3) {  // k : 前日と被らない活動の添字
        if(!i) {
          // 二日目は被らない
          chmax(dp[i + 1][j], dp[i][j]);
          continue;
        }
        /* 前日に行った活動と被らなければ */
        if(j != k) {
          chmax(dp[i + 1][j], dp[i][k] + v[i][j]);
        }
      }
    }
  }
  int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
  CO(ans);
}

int main() {
  FAST;
  // clock_t start = clock();
  solve();
  // clock_t end = clock();
  // double time = end - start;
  // cout << time << " ms" << en;
  // cout << time / 1000 << " s" << en;
}