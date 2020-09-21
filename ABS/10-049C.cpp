#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  vector<string> T = {"dream", "dreamer", "erase", "eraser"};
  rep(i, T.size()) reverse(T[i].begin(), T[i].end());

  while (S.size() != 0) {
    if (S.substr(0, 5) == T[0] || S.substr(0, 5) == T[2]) {
      S = S.substr(5);
    } else if (S.substr(0, 6) == T[3]) {
      S = S.substr(6);
    } else if (S.substr(0, 7) == T[1]) {
      S = S.substr(7);
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
}