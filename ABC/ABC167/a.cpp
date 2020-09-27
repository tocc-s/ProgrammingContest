#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9+7;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()

int main() {
  string S, T;
  cin >> S >> T;
  int S_len = S.length();

  int cnt = 0;

  for(int i = 0; i < S_len; i++) {
    if(S[i] == T[i]) cnt++;
  }

  if(cnt == S_len) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}