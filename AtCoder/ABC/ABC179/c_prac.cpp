#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using OVEC = vector<int>;
using TVEC = vector<vector<int>>;
constexpr LL MOD = 1e9 + 7;
constexpr LL LINF = 1e18;
constexpr int IINF = 1e9;
constexpr double PI = 3.14159265358979323846;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPE(i, n) for (int i = 0; i <= n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORE(i, m, n) for (int i = m; i <= n; i++)
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), v.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
void string_lower(string& s, int n) {
  s[n] = s[n] + ('a' - 'A');
}
void string_upper(string& s, int n) {
  s[n] = s[n] - ('a' - 'A');
}
#pragma endregion

int main() {
  // cout << fixed << setprecision(15);
  int n, cnt = 0;
  cin >> n;

  // a*b+c = n
  // 正整数なのでa, bの初期値は1
  // cはa*bの組み合わせが決まれば1通りに絞られるため、n未満だけa*bの通りをカウントする a*b = n-c :(cは1)
  for(int a = 1; a < n; a++) {
    for(int b = 1; a*b < n; b++) {
      cnt++;
    }
  }

  CO(cnt);
}