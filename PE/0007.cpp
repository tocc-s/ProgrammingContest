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

/* 素数判定 */
template<class T>
bool is_prime(T n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0 || n % 2 == 0) return false;
  }
  return true;
}

int main() {
  CLS;
  FAST;
  int n;
  // cin >> n;

  VEC<int> primes;
  int cnt = 0;
  n = 105000;
  cout << "input n: " << n << '\n';
  FORE(i, 2, n) {
    if (is_prime(i)) {
      primes.emplace_back(i);
      cnt++;
    }
    if(cnt == 10001) break;
  }

  int itr_cnt = 0;
  FORR(itr, primes) {
    itr_cnt++;
    if(itr_cnt == 10001) CO(itr);
  }

  // ans: 104743
  CLE;
}