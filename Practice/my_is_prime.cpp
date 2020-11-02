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
constexpr LL LLINF = LLONG_MAX;
constexpr int IINF = INT_MAX;
constexpr int MOD = 1e9 + 7;
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

void prime_check(int n) {
  VEC<int> primes;
  bool notprime = false;

  FOR(i, 2, n) {  // 2 から n まで素数判定を行う ( 1 は素数ではないので 2 から)
    /* ~2 から その数-1まで ( 1 とその数自身以外)~ */
    FORE(j, 2, sqrt(i)) {  // 合成数の性質により、2 から √x までについて割り切れるかどうかを調べれば十分らしい    
      if (i % 2 == 0 || i % j == 0) {   // もしも偶数、または割り切れるなら
        notprime = true;  // 素数ではない
        break;
      };
    }
    if (!notprime) primes.emplace_back(i);
    notprime = false;
  }

  REP(i, primes.size()) CO(primes[i]);
}

int main() {
  CLS;
  FAST;
  int n;
  cin >> n;

  prime_check(n);
  CLE;
}