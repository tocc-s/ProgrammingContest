#include <bits/stdc++.h>
using namespace std;
#define rep(i, A, B) for (long long i = A; i <= (long long)(B); i++)

int main() {
  long long A, B, C, D;
  int cnt = 0;
  cin >> A >> B >> C >> D;
  rep(i, A, B) {
    if (i % (C * D) != 0) cnt++;
  }
  cout << cnt << '\n';
}