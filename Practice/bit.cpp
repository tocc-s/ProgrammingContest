#include <bits/stdc++.h>
using namespace std;

/* 部分和問題 */
/* n 個の正の整数 a[0],a[1],…,a[n−1]a[0],a[1],…,a[n−1] と正の整数 W
 * が与えられる。これらの整数から何個かの整数を選んで総和が W
 * になるようにすることが可能か判定せよ。可能ならば "YES" と出力し、不可能ならば
 * "NO" と出力せよ。*/

void YorN(bool flag) {
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  // i < (1 << N): 選ばれている数を2^N通り全探索
  bool flag = false;
  for (int bit = 0; bit < (1 << n); bit++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      // bitを2進数表記で表した時、i番目にbitが立っていたら
      if (bit & (1 << i)) sum += a[i];
    }

    if (sum == w) flag = true;
  }

  YorN(flag);
}