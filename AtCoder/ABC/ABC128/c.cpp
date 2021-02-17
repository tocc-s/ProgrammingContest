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
  int n, m;
  cin >> n >> m;
  VEC2<int> s;
  VEC<int> p(m);

  REP(i, 0, m) {
    int k;
    cin >> k;
    s.emplace_back();
    REP(j, 0, k) {
      int ts;
      cin >> ts;
      ts--;
      s[i].emplace_back(ts);
    }
  }
  REP(i, 0, m) cin >> p[i];

  /* debug */
  // CO();
  // REP(i, 0, m) {
  //   REP(j, 0, s[i].size()) { cout << s[i][j] << " "; }
  //   CO();
  // }

  int ans = 0;
  /* スイッチのon,offパターンをビット全探索 */
  REPBIT(n) {
    /* debug */
    // cout << bitset<8>(bit) << en;
    VEC<bool> flg(m, false);
    REP(i, 0, m) {
      int s_sum = 0;
      /* スイッチがonの箇所を探索 */
      REP(j, 0, s[i].size()) {
        if(bit & (1 << s[i][j])) s_sum++;
      }
      /* スイッチがonになっている数の余りが条件に適っていれば */
      if(s_sum % 2 == p[i]) flg[i] = true;
    }

    /* 全ての電球が点灯しているか */
    bool tf = true;
    REP(i, 0, m) {
      /* debug */
      // CO(flg[i]);
      if(!flg[i]) {
        tf = false;
        break;
      }
    }
    if(tf) ans++;
  }

  CO(ans);
}

int main() {
  FAST;
  solve();
}