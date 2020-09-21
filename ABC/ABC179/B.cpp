#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, D1, D2, cnt=0, max=-1; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> D1 >> D2;
    if(D1 == D2) {
      cnt++;
    } else {
      cnt = 0;
    }
    if(max <= cnt) max = cnt;
  }

  if(max >= 3) cout << "Yes" << endl;
  else cout << "No" << endl;
}