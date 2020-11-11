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
template <class T>
using P = pair<T, T>;
template <class T>
using VEC = vector<T>;
template <class T>
using VEC2 = vector<vector<T>>;
using PQ = priority_queue<int>;
using RPQ = priority_queue<int, vector<int>, greater<int>>;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FREV(i, m, n) for (int i = m; i >= n; i--)
#define FORR(itr, dict) for (auto& itr : dict)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
#define en '\n'
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr int MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
#pragma endregion Defines

#pragma region Functions
void string_lower(string& s, int n) {
  if (s[n] >= 65 && s[n] <= 90) s[n] = s[n] + ('a' - 'A');
}
void string_upper(string& s, int n) {
  if (s[n] >= 97 && s[n] <= 122) s[n] = s[n] - ('a' - 'A');
}
template <class T>
void CO(T value) {
  cout << value << en;
}
void CO(void) { cout << en; }
int ctoi(char c) {
  if ('0' <= c && c <= '9')
    return (c - '0');
  else {
    CO("ctoi error!");
    return -1;
  }
}
char itoc(int n) { return n + '0'; }
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool int_chk(T n) {
  if (ceil(n) == floor(n)) return true;
  return false;
}
#pragma endregion Functions

#pragma endregion Template
///////////////////////////////////////////////////////////////////////////////

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  VEC<int> l(n), r(n);
  REP(i, n) cin >> l[i] >> r[i];

  REP(i, n) {
    queue<char> tmp;
    for (int j = r[i] - 1; j >= l[i] - 1; j--) {
      tmp.push(s[j]);
    }
    FORE(j, l[i] - 1, r[i] - 1) {
      s[j] = tmp.front();
      tmp.pop();
    }
  }

  CO(s);
}

int main() {
  FAST;
  solve();
}