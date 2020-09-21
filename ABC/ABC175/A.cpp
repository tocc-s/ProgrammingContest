#include <bits/stdc++.h>
using namespace std;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int cnt = 0;
  string S;
  cin >> S;

  if (S[0] == 'R') {
    cnt++;
    if (S[1] == 'R') {
      cnt++;
      if (S[2] == 'R') {
        cnt++;
      }
    } else {
      cnt = 1;
    }
  } else {
    cnt = 0;
    if (S[1] == 'R') {
      cnt++;
      if (S[2] == 'R') {
        cnt++;
      }
    } else {
      if (S[2] == 'R') {
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}