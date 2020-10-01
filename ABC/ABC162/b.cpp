#pragma region includes
#include <bits/stdc++.h>
using namespace std;
#pragma endregion
#pragma region defines
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), V.end()
template <class T>
void CO(T value) { cout << value << endl; }
#pragma endregion

int main() {
  int N, cnt = 1;
  ll sum = 0;
  cin >> N;

  while(1) {
    if(cnt % 3 == 0 && cnt % 5 == 0){
      // CO("FizzBuzz");
    } else if(cnt % 3 == 0) {
      // CO("Fizz");
    } else if(cnt % 5 == 0) {
      // CO("Buzz");
    } else {
      sum += cnt;
    }
    cnt++;
    if(cnt > N) break;
  }
  CO(sum);
}