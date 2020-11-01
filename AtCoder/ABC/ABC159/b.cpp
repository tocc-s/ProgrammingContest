#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll MOD = 1e9 + 7;
constexpr ll LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(n < 7) {
    CO("No");
    return 0;
  }
  int if1 = ((n - 1) / 2) - 1, if2 = ((n + 3) / 2) - 1;
  bool flag1 = 0, flag2 = 0, flag3 = 0;

  REPE(i, n / 2 - 1) {
    if (s[i] == s[(n - 1) - i]) {
      flag1 = 1;
    } else {
      CO("No");
      return 0;
    }
    // CO(flag1);
  }
  REPE(i, if1 / 2 - 1) {
    if (s[i] == s[if1 - i]) {
      flag2 = 1;
    } else {
      CO("No");
      return 0;
    }
    // CO(flag2);
  }
  // int index = 0;
  // FORE(i, if2, if2 + (n - if2) / 2) {
  //   if (s[i] == s[(n - 1) - index]) {
  //     flag3 = 1;
  //   } else {
  //     CO("No");
  //     return 0;
  //   }
  //   // CO(flag3);
  //   index++;
  // }
  // cout << flag1 << flag2 << flag3;

  if (flag1 && flag2) // && flag3)
    CO("Yes");
  else
    CO("No");
}