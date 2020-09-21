#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K, N, cnt = 0;
  cin >> A >> B >> K;
  if (A > B)
    N = A;
  else
    N = B;

  for (int i = N; i > 0; i--) {
    if (A % i == 0 && B % i == 0) {
      cnt++;
      // cout << i << " " << cnt << endl;
    }
    if (cnt == K) {
      cout << i << endl;
      return 0;
    }
  }
}