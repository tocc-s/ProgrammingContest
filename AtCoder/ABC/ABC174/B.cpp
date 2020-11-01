#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt = 0;
  long long D;
  cin >> N >> D;
  // vector<long long> X(N), Y(N);
  long long X, Y;

  rep(i, N) {
    // cin >> X[i] >> Y[i];
    // if(sqrt((X[i]*X[i])+(Y[i]*Y[i])) <= D) cnt++;
    cin >> X >> Y;
    if (sqrt((X * X + Y * Y)) <= D) cnt++;
  }
  cout << cnt << '\n';
}