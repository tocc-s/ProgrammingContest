#include <bits/stdc++.h>
using namespace std;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  int S_len = S.length(), T_len = T.length(), min_cnt = 1001, cnt = 0;

  if (S.find(T) != std::string::npos) {
    cout << cnt << endl;
    return 0;
  }

  for (int i = 0; i < S_len; i++) {
    for (int j = 0; j < T_len; j++) {
      if (T[j] == S[i+j]) {
        cnt++;
        cout << T[j] << " " << S[i+j] << endl;
      }
    }
    if (min_cnt > cnt) min_cnt = cnt;
    cnt = 0;
  }
  cout << min_cnt << endl;
}