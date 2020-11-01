#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cnt = 0;
  cin >> N;
  string cmp = "ABC";
  vector<char> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  for (int i = 0; i < N - 2; i++) {
    if (S[i] == cmp[0]) {
      if (S[i + 1] == cmp[1]) {
        if (S[i + 2] == cmp[2]) {
          cnt++;
        } else
          continue;
      } else
        continue;
    } else
      continue;
  }
  cout << cnt << endl;
}