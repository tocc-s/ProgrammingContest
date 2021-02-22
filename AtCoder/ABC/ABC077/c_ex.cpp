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

/* 二分探索 */
// イテレータ : 二分探索の場合、条件に合った配列の要素の添え字(x) = ex[x <- コレ]
// *イテレータ : 二分探索の場合、条件に合った配列の要素(ex[x])
// upper_bound() : key より大きい要素の内の一番左側のイテレータを返す
// lower_bound() : key 以上の要素の内の一番左側のイテレータを返す
/* ----------------------------------------------------------- */
// upper_bound() - 先頭イテレータ[ex.begin()] = key 以下の*個数*
// 末尾イテレータ[ex.end()] - lower_bound() = key 以上の*個数*
// lower_bound() - 先頭イテレータ[ex.begin()] = key 未満の*個数*
// 末尾イテレータ[ex.end()] - upper_bound() = key 超過の*個数*

void solve() {
  int n;
  cin >> n;
  VEC<int> a(n), b(n), c(n);
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) cin >> b[i];
  REP(i, 0, n) cin >> c[i];
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));

  LL ans = 0;
  REP(j, 0, n) {  // 配列 b を固定
    /* lower_bound() - 先頭イテレータ = key 未満の*個数* */
    int i = lower_bound(ALL(a), b[j]) - a.begin();
    /* 末尾イテレータ - upper_bound() = key 超過の*個数* */
    int k = c.end() - upper_bound(ALL(c), b[j]);
    ans += i * k;
  }
  CO(ans);
}

int main() {
  FAST;
  solve();
}