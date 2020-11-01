#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt = 0, index = 0;
  cin >> N;
  bool zero = false, nine = false;
  ull sub = 1000000007;
  if (N == 1) {
    cout << "0" << endl;
    return 0;
  }

  while (index < N) {
    for (int i = 0; i <= 9; i++) {
      if (i == 0)
        zero = true;
      else if (i == 9)
        nine = true;
      if (!zero && !nine) continue;

      for (int j = 9; j >= 0; j--) {
        if (j == 9)
          nine = true;
        else if (j == 0)
          zero = true;

        if (zero && nine) {
          cnt++;
          break;
        }
      }
      zero = false;
      nine = false;
    }
    index++;
  }
  cout << cnt % sub << endl;
}