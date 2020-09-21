#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, cnt = 0;
  cin >> N;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  sort(L.begin(), L.end());

  for(int i = 0; i < (int)(N); i++) {
    for(int j = 0; j < i; j++) {
      for(int k = 0; k < j; k++) {
        if (L[i] != L[j] && L[j] != L[k] && L[j] + L[k] > L[i]) cnt++;
      }
    }
  }
  cout << cnt << endl;
}