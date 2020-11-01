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
  int N;
  cin >> N;

  if(N % 10 == 2 || N % 10 == 4 || N % 10 == 5 || N % 10 == 7 || N % 10 == 9) {
    cout << "hon" << endl;
  } else if(N % 10 == 0 || N % 10 == 1 || N % 10 == 6 || N % 10 == 8) {
    cout << "pon" << endl;
  } else if(N % 10 == 3) {
    cout << "bon" << endl; 
  }
  
}