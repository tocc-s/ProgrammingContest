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
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  string o, e;
  cin >> o >> e;
  int ans_size;
  bool flag;

  if (o.size() > e.size()) {
    ans_size = o.size();
    flag = true;
  } else {
    ans_size = e.size();
    flag = false;
  }

  REP(i, ans_size) {
    if(o.size() - e.size() == 0 || i < ans_size-1) {
      cout << o[i] << e[i];
    } else if(flag && i == ans_size-1) {
      cout << o[i];
    } else if(!flag && i == ans_size-1) {
      cout << e[i];
    }
  }
  cout << endl;
}