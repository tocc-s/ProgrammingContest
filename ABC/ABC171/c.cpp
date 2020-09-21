#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n;
  string ans = "abcdefghijklnmopqrstuvwxyz";
  int index = 0;
  cin >> n;

  while (n > 0) {
    if ((n % 26) == 0) {
      ans[index] = 'a' + 26;
    } else {
      ans[index] = 'a' + (n % 26) - 1;
    }
    n /= 26;
    index++;
  }
  cout << ans << '\n';
}