#pragma region Region
#pragma region Includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region Setting
#pragma GCC optimize("Ofast")
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
#define CLS clock_t start = clock();
#define CLE              \
  clock_t end = clock(); \
  cout << end - start << " ms" << '\n';
#pragma endregion
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
#define FORR(itr, dict) for (auto& itr : dict)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
constexpr int MOD = 1e9 + 7;
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr double PI = 3.14159265358979323846;
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
template <class T>
void CO(T value) {
  cout << value << "\n";
}
#pragma endregion
#pragma endregion Region
///////////////////////////////////////////////////////////////////////////////

/* データ型の最大値の確認(https://qiita.com/hryshtk/items/b848ed3bd78f940ac5af) */
int main() {
  FAST;
  short s = 32767;                           // 2^15-1
  unsigned short us = 65535;                 // 2^16-1
  int i = 2147483647;                        // 2^31-1
  unsigned int ui = 4294967295;              // 2^32-1
  long l = 2147483647;                       // 2^31-1
  unsigned long ul = 4294967295;             // 2^32-1
  long long ll = (1LL << 63) - 1;            // 2^63-1
  unsigned long long ull = (1LL << 64) - 1;  // 2^64-1

  cout << "short: " << s << endl;
  cout << "unsigned short: " << us << endl;
  cout << "int: " << i << endl;
  cout << "unsigned int: " << ui << endl;
  cout << "long: " << l << endl;
  cout << "unsigned long: " << ul << endl;
  cout << "long long: " << ll << endl;
  cout << "unsigned long long: " << ull << endl;
  cout << endl;

  //オーバーフローするかどうかの実験
  s += 1;
  us += 1;
  i += 1;
  ui += 1;
  l += 1;
  ul += 1;
  ll += 1;
  ull += 1;
  CO("*** OF ***");
  cout << "short: " << s << endl;
  cout << "unsigned short: " << us << endl;
  cout << "int: " << i << endl;
  cout << "unsigned int: " << ui << endl;
  cout << "long: " << l << endl;
  cout << "unsigned long: " << ul << endl;
  cout << "long long: " << ll << endl;
  cout << "unsigned long long: " << ull << endl;
  cout << endl;

  //実際値
  CO("*** MAX ***");
  cout << "short: " <<  SHRT_MAX << endl;
  cout << "unsigned short: " << USHRT_MAX << endl;
  cout << "int: " << INT_MAX << endl;
  cout << "unsigned int: " << UINT_MAX << endl;
  cout << "long: " << LONG_MAX << endl;
  cout << "unsigned long: " << ULONG_MAX << endl;
  cout << "long long: " << LLONG_MAX << endl;
  cout << "unsigned long long: " << ULLONG_MAX << endl;
  cout << endl;

  // //オーバーフローするかどうかの実験
  // s = SHRT_MAX + 1;
  // us = USHRT_MAX + 1;
  // i = INT_MAX + 1;
  // ui = UINT_MAX + 1;
  // l = LONG_MAX + 1;
  // ul = ULONG_MAX + 1;
  // ll = LLONG_MAX + 1;
  // ull = ULLONG_MAX + 1;
  // CO("*** MAX OF ***");
  // cout << "short: " <<  SHRT_MAX << endl;
  // cout << "unsigned short: " << USHRT_MAX << endl;
  // cout << "int: " << INT_MAX << endl;
  // cout << "unsigned int: " << UINT_MAX << endl;
  // cout << "long: " << LONG_MAX << endl;
  // cout << "unsigned long: " << ULONG_MAX << endl;
  // cout << "long long: " << LLONG_MAX << endl;
  // cout << "unsigned long long: " << ULLONG_MAX << endl;
  // cout << endl;

  cout << "LLINF: " << LLINF << "\n";
  cout << "IINT: " << IINF << "\n";

  return 0;
}