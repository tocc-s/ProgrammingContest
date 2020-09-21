#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt = 0;
  cin >> N;
  char tmp;
  vector<char> c(N);
  rep(i, N) cin >> c[i];

  rep(i, N) {
    if (i != 0 && c[i] == 'R') {
      if (c[0] == 'W') {
        tmp = c[0]; c[0] = c[i]; c[i] = tmp;  //入れ替え
        cnt++;
      }
    }
    if (c[i - 1] == 'R' && c[i] == 'W') {
      int j = i;
      rep(j, N) {
        if (c[j] == 'R') {
          tmp = c[j]; c[j] = c[i]; c[i] = tmp;  //入れ替え
          cnt++;
        }
      }
    }
    if (c[i-1] == 'W' && c[i] == 'R') {
      c[i] = 'W';
      cnt++;
    }
  }
  cout << cnt << '\n';
}