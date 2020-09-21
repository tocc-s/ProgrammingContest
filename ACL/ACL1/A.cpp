#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, cnt;
  cin >> N;
  vector<int> x(N), y(N), ans(N);
  for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

  for (int i = 0; i < N; i++) {
    cnt = 1;
    if (i != N) {
      for (int j = i + 1; j < N; j++) {
        if ((x[i] < x[j] && y[i] < y[j]) || (x[i] > x[j] && y[i] > y[j])) {
          cnt++;
        }
      }
    }
    if (i != 0) {
      for (int h = i - 1; h >= 0; h--) {
        if ((x[i] < x[h] && y[i] < y[h]) || (x[i] > x[h] && y[i] > y[h])) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
}