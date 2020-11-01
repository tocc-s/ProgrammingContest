#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s, t; int cnt = 0;
  cin >> s;
  cin >> t;
  rep(i, s.length()){
    if(s[i] != t[i]) cnt++;
  }
  cout << cnt << '\n';
}