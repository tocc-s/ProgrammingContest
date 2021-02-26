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
  int n, w_max;
  cin >> n >> w_max;
  VEC<int> w(n), v(n);
  REP(i, 0, n) cin >> w[i] >> v[i];

  VEC2<LL> dp(n + 10, VEC<LL>(w_max + 10));
  REPE(i, 0, w_max) dp[0][i] = 0;

  REP(i, 0, n) {         // i : 荷物の順番
    REPE(j, 0, w_max) {  // j : ナップザックに入る容量
      /* 現在のナップザックに入る容量(j) が w[i] を上回っている時、 v[i] の荷物を入れられる */
      if(j >= w[i]) {
        /* 既に入っている(容量 j - w[i] の荷物)を取り除いて、(w[i]、v[i]) の荷物を入れた場合、
           (容量 j - w[i] の荷物) の荷物よりも価値が上がれば更新  */
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
      } else {  // そうでなければ、容量が限界のため入れられない
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
  CO(dp[n][w_max]);
}

int main() {
  FAST;
  solve();
}