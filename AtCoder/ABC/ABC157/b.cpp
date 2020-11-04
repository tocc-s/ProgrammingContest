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
#define CLS clock_t start = clock();
#define CLE              \
  clock_t end = clock(); \
  cout << end - start << " ms" << '\n';
#pragma endregion Setting

#pragma region Defines
using LL = long long;
template <class T>
using P = pair<T, T>;
template <class T>
using VEC = vector<T>;
template <class T>
using GRAPH = vector<vector<T>>;
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
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
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
#pragma endregion Functions

#pragma endregion Template
///////////////////////////////////////////////////////////////////////////////

int main() {
  FAST;
  GRAPH<int> card(3, VEC<int>(3));
  GRAPH<bool> cf(3, VEC<bool>(3, false));
  REP(i, 3) { REP(j, 3) cin >> card[i][j]; }
  int n;
  cin >> n;
  REP(i, n) {
    int b;
    cin >> b;

    REP(i, 3) {
      REP(j, 3) {
        if (b == card[i][j]) cf[i][j] = true;
      }
    }
  }

  bool flag = false;
  REP(i, 3) {
    if (cf[i][0] && cf[i][1] && cf[i][2]) flag = true;  // 横
    if (cf[0][i] && cf[1][i] && cf[2][i]) flag = true;  // 縦
  }
  if (cf[0][0] && cf[1][1] && cf[2][2]) flag = true;  // 右下がり
  if (cf[2][0] && cf[1][1] && cf[0][2]) flag = true;  // 右上がり
  
  if (flag)
    CO("Yes");
  else
    CO("No");
}