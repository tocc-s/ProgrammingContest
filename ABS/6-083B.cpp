#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, ans = 0;
  cin >> N >> A >> B;
  string s;  

  for (int i = 1; i <= N; i++) {
    int sum = 0;
    s = to_string(i);
    for (int j = 0; j < (int)s.size(); j++) {
      sum += (s[j] - '0');
    }
    if (sum >= A && sum <= B) ans += i;
  }
  cout << ans << endl;
}