#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using LL = long long;
using PLL = pair<LL, LL>;
using VEC = vector<int>;
using GRAPH = vector<vector<int>>;
using PQ = priority_queue<int>;
using RPQ = priority_queue<int, vector<int>, greater<int>>;
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
#define SETPRE(n) cout << fixed << setprecision(n)
template <class T>
void CO(T value) {
  cout << value << endl;
}
void string_lower(string& s, int n) { s[n] = s[n] + ('a' - 'A'); }
void string_upper(string& s, int n) { s[n] = s[n] - ('a' - 'A'); }
#pragma endregion

int main() {
  int n, k;
  cin >> n >> k;
  PQ h;
  REP(i, n) {
    int hp;
    cin >> hp;
    h.push(hp);
  }
  if(h.size() <= k) {
    CO(0);
    return 0;
  }

  while(k != 0) {
    h.pop(); 
    k--;
  }

  LL sum = 0;
  while (!(h.empty())) {
    sum += h.top();
    h.pop();
  }
  CO(sum);
}