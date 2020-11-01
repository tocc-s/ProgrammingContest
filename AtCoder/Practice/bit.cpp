#include <bits/stdc++.h>
using namespace std;

/* 部分和問題 */

void YorN(bool flag) {
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
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
      //iを2進数表記で表した時、j番目にbitが立っていたら
      if(i & (1 << j)) sum += a[j];
    }

    if(sum == W) flag = true;
  }
  
  YorN(flag);
}