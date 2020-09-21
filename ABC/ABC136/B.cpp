#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, keta = 1, keta_cnt = 1, cnt = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    keta = i;
    while (keta >= 10) {      
      keta /= 10;      
      keta_cnt++;
    }
    if(keta_cnt % 2 == 1) {
      cnt++;
    }
    keta_cnt = 1;
  }
  cout << cnt << endl;
}