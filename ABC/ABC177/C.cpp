#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, pow_num = 1000000007;
  cin >> N;
  vector<long> A(N);
  rep(i, N) cin >> A[i];
  long long ans = 0;

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      ans += A[i] * A[j];
    }
  }
  cout << ans % pow_num << endl;
}