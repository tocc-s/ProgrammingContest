#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w, k, cnt = 0;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i, h) cin >> c[i];

  rep(i, h){    
    rep(j, w){
      if(c[i][j] == '#') cnt++;
    }    
  }
  cout << cnt << '\n';
}