#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, index = 0, _min = 1001, cnt = 0, sum = 0;
  cin >> N >> K;
  vector<int> p(N);
  rep(i, N) cin >> p[i];

  sort(p.begin(), p.end());

  rep(i, K) sum += p[i];

  cout << sum << '\n';
  // while(cnt < K) {
  //   _min = 1001;
  //   rep(i, N) {
  //     if (p[i] < _min) {
  //       _min = p[i];
  //       index = i;
  //     }
  //   }
  //   sum += _min;
  //   cnt++;
  //   p[index] = 1001;
  // }
}