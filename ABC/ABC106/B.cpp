#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cnt = 0, ans_cnt = 0;
  cin >> N;

  for(int i = 1; i <= N; i++) {
    if(i % 2 == 1) {
      for(int j = 1; j <= i; j++) {
        if(i % j == 0) cnt++;
      }
    } else continue;
    if(cnt == 8) ans_cnt++;
    cnt = 0;
  }
  cout << ans_cnt << endl;
}