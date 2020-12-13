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

void solve() {
  int n, m;
  cin >> n >> m;
  if(m == 0) {
    CO(1);
    return;
  }
  VEC<bool> v(n, false);
  VEC<int> len;
  REP(i, 0, m) {
    int tmp;
    cin >> tmp;
    v[tmp - 1] = true;
  }
  if(n == m) {
    CO(0);
    return;
  }

  int cnt = 0, mi = IINF;
  bool flag = false;
  REP(i, 0, n) {
    if(!v[i]) {
      flag = true;

    } else {
      flag = false;
    }

    if(flag) {
      cnt++;
      if(i == n - 1) len.emplace_back(cnt);
    } else {
      if(cnt != 0) {
        len.emplace_back(cnt);
      }
      // chmin(mi, cnt);
      cnt = 0;
    }
  }

  mi = *min_element(ALL(len));

  int ans = 0;
  REP(i, 0, len.size()) {
    // CO(len[i]);
    ans += len[i] / mi;
    if(len[i] % mi != 0) ans++;
  }
  CO(ans);
}

int main() {
  FAST;
  solve();
}