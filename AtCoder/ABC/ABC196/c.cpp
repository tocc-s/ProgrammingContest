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
  LL n;
  cin >> n;

  LL ans = 0;
  if(n < 100) {
    for(LL i = 11; i <= n; i += 11) {
      ans++;
    }
    CO(ans);
    return;
  }

  if(n >= 100) ans += pow(9, 1) + 1;
  if(n >= 10000) ans += pow(9, 2) + 1;
  if(n >= 1000000) ans += pow(9, 3) + 1;
  if(n >= 100000000) ans += pow(9, 4) + 1;
  if(n >= 10000000000) ans += pow(9, 5) + 1;

  if(n >= 100 && n < 10000) {
    for(LL i = 1111; i <= n; i += 101) {
      ans++;
    }
  }
  if(n >= 10000 && n < 1000000) {
    for(LL i = 111111; i <= n; i += 1001) {
      ans++;
    }
  }
  if(n >= 1000000 && n < 100000000) {
    for(LL i = 11111111; i <= n; i += 10001) {
      ans++;
    }
  }
  if(n >= 100000000 && n < 10000000000) {
    for(LL i = 1111111111; i <= n; i += 100001) {
      ans++;
    }
  }
  if(n >= 10000000000 && n < 1000000000000) {
    for(LL i = 111111111111; i <= n; i += 1000001) {
      ans++;
    }
  }

  CO(ans);
}

int main() {
  FAST;
  solve();
}