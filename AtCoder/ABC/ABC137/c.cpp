#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
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
#define FORR(itr, dict) for (auto itr = dict.begin(); itr != dict.end(); itr++)
#define ALL(v) v.begin(), v.end()
#define SETPRE(n) cout << fixed << setprecision(n)
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i, n) cin >> s[i];

  unordered_map<string, int> dict{};
  LL ans = 0;
  REP(i, n) {
    sort(ALL(s[i]));
    // cout << "sorted = " << s[i] << endl;
    if (dict.count(s[i])) {  // アナグラムが同じ
      dict[s[i]]++;
      ans += dict[s[i]]; // 過去に見つかっている分組み合わせが存在するため、その数を追加する
    } else {  // アナグラムが違う
      dict.emplace(s[i], 0);
    }
  }

  CO(ans);
}