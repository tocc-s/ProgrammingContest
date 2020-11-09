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
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  // i < (1 << N): 選ばれている数を2^N通り全探索
  bool flag = false;
  for (int i = 0; i < (1 << N); i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      // iを2進数表記で表した時、j番目にbitが立っていたら
      if (i & (1 << j)) sum += a[j];
    }

    if (sum == W) flag = true;
  }

  YorN(flag);
}