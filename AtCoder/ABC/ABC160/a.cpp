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
#define FORR(v, vec) for (auto const& v : vec)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) { cout << value << endl; }
#pragma endregion

int main() {
  string S;
  cin >> S;

  if(S[2] == S[3] && S[4] == S[5]) CO("Yes");
  else CO("No");  
}