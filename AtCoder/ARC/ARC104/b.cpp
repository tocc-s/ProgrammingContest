#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 1; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) {
  cout << value << endl;
}
#pragma endregion

int main() {
  int N;
  string S;
  cin >> N >> S;

  int cnt = 0, l_cnt = 1, l_atcg = 1;
  bool f_AT = false, f_CG = false, f_ATCG = false;
  REP(i, N) {
    if (S[i - 1] == S[i]) {
      f_AT = false;
      f_CG = false;
      f_ATCG = false;
      l_cnt = 1;
    }

    if (S[i - 1] != S[i]) {
      f_ATCG = true;
      l_cnt++;
      l_atcg++;
      if (S[i - 1] == 'A' || S[i - 1] == 'T') {
        f_AT = true;
        f_CG = false;
      } else {
        f_CG = true;
        f_AT = false;
      }
      if(l_cnt >= 3 && (f_AT || f_CG)) f_ATCG = false;
      if(f_ATCG && l_atcg== 4) {
        cnt++;
        f_ATCG = false;
        l_atcg = 1;
        CO("ATCG");
      }

      if(f_AT && (S[i] == 'C' || S[i] == 'G')) {
        f_AT = false;
        l_cnt = 1;
      }
      if(f_CG && (S[i] == 'A' || S[i] == 'T')) {
        f_CG = false;
        l_cnt = 1;
      }

      if (f_AT && (S[i] == 'A' || S[i] == 'T')) {
        cnt++;
        if (l_cnt > 2 && l_cnt % 2 == 0) {
          cnt++;
          l_atcg = 1;
        }
      }
      if (f_CG && (S[i] == 'C' || S[i] == 'G')) {
        cnt++;
        if (l_cnt > 2 && l_cnt % 2 == 0) {
          cnt++;
          l_atcg = 1;
        }
      }     
    }
  }
  CO(cnt);
}