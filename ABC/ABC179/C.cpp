#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, A = 1, B = 1, C = 1, cnt = 0;
  cin >> N;

  for (int C = 1; C < N; C++) {
    for (int B = 1; B < N; B++) {
      if (C + B > N) break;
      for (int A = 1; A < N; A++) {
        if ((A * B + C) > N) {
          break;
        }
        if ((A * B + C) == N) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}